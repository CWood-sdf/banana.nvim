/**
 * @file HTML grammar for tree-sitter
 * @author Max Brunsfeld
 * @auther CWood-sdf
 * @license MIT
 */

/* eslint-disable arrow-parens */
/* eslint-disable camelcase */
/* eslint-disable-next-line spaced-comment */
/// <reference types="tree-sitter-cli/dsl" />
// @ts-check
module.exports = grammar({
    name: "nml",

    extras: ($) => [$.comment, /\s+/],
    externals: ($) => [$.if_clause, $.sentinel],

    rules: {
        source_file: ($) => repeat($._node),
        _start_tag_name: (_) =>
            choice(
                "a",
                "nml",
                "title",
                "pre",
                "head",
                "body",
                "div",
                "p",
                "span",
                "ol",
                "ul",
                "template",
                "li",
                "slot",
                /h[1-6]/,
                /(\w+-)+\w+/,
                /[A-Z_][\w+\-_\/]+/,
            ),
        raw_text: (_) => /[^<]+/,
        _script_start_tag_name: (_) => "script",
        _style_start_tag_name: (_) => "style",
        _end_tag_name: ($) => $._start_tag_name,
        erroneous_end_tag_name: (_) => /[^>\s]+/,
        comment: (_) =>
            seq("<!--", repeat(choice(/[^-]/, /\-[^-]/, /--[^>]/)), "-->"),
        self_closing_tags: (_) => choice("meta", "br", "canvas", "hr", "bound"),

        templating_name: (_) => /[\w_][\w_\d]*/,

        templating_decl_if: ($) => seq(alias("if", $.conditional), $.if_clause),
        // a regex that stops matching if one } is reached, but not if 2 are
        // if_clause: () => /[^}\s](?:(})+|[^}\s])*\s*/,

        named_variable: () => /[\w_]+[\w_\d]*/,

        templating_decl_for: ($) =>
            seq(
                alias("for", $.conditional),
                $.named_variable,
                repeat(seq(alias(",", $.comma), $.named_variable)),
                alias("in", $.loop_in),
                $.if_clause,
            ),

        conditional: (_) => choice("if", "for"),

        templating_decl: ($) =>
            choice($.templating_decl_if, $.templating_decl_for),

        templating_repeat_elseif: ($) =>
            seq(alias("elseif", $.conditional), $.if_clause),

        templating_repeat_else: ($) => alias("else", $.conditional),
        templating_repeat_decl: ($) =>
            choice($.templating_repeat_elseif, $.templating_repeat_else),

        templating_cont_open: (_) => "{:",
        templating_open: (_) => "{#",
        templating_close: (_) => "}",

        template_repeat: ($) =>
            seq(
                $.templating_cont_open,
                $.templating_repeat_decl,
                $.templating_close,
            ),
        templating_close_start: (_) => "{/",

        templating: ($) =>
            seq(
                $.templating_open,
                $.templating_decl,
                $.templating_close,
                repeat(choice($._node, /\s+/, $.template_repeat)),
                $.templating_close_start,
                $.conditional,
                $.templating_close,
            ),

        document: ($) => repeat($._node),

        doctype: ($) => seq("<!", alias($._doctype, "doctype"), /[^>]+/, ">"),

        _doctype: (_) => /[Dd][Oo][Cc][Tt][Yy][Pp][Ee]/,

        _node: ($) =>
            choice(
                $.doctype,
                $.entity,
                $.substitution,
                $.templating,
                $.text,
                $.element,
                $.script_element,
                $.style_element,
                $.erroneous_end_tag,
            ),

        element: ($) =>
            choice(
                seq($.start_tag, repeat($._node), choice($.end_tag)),
                $.self_closing_tag,
            ),

        script_element: ($) =>
            seq(
                alias($.script_start_tag, $.start_tag),
                optional($.raw_text),
                $.script_end_tag,
            ),

        style_element: ($) =>
            seq(
                alias($.style_start_tag, $.start_tag),
                optional($.raw_text),
                $.style_end_tag,
            ),

        start_tag: ($) =>
            seq(
                "<",
                alias($._start_tag_name, $.tag_name),
                repeat(choice($.attribute, "\n", "\r")),
                ">",
            ),

        script_start_tag: ($) =>
            seq(
                "<",
                alias($._script_start_tag_name, $.tag_name),
                repeat($.attribute),
                ">",
            ),
        script_end_tag: ($) =>
            seq("</", alias($._script_start_tag_name, $.tag_name), ">"),

        style_start_tag: ($) =>
            seq(
                "<",
                alias($._style_start_tag_name, $.tag_name),
                repeat($.attribute),
                ">",
            ),
        style_end_tag: ($) =>
            seq("</", alias($._style_start_tag_name, $.tag_name), ">"),

        self_closing_tag: ($) =>
            seq(
                "<",
                alias($.self_closing_tags, $.tag_name),
                repeat($.attribute),
                // html spec says that self closing tags are only self closing bc of the tag name, not bc of the />
                // it also says that the /> is a parser error that is just ignored
                choice("/>", ">"),
            ),

        end_tag: ($) =>
            seq("</", alias($._end_tag_name, $.tag_name), /s*/, ">"),

        erroneous_end_tag: ($) => seq("</", $.erroneous_end_tag_name, ">"),

        attribute: ($) =>
            seq(
                $.attribute_name,
                optional(
                    seq(
                        "=",
                        choice($.attribute_value, $.quoted_attribute_value),
                    ),
                ),
            ),

        attribute_name: (_) => /[^<>"'/=\s]+/,

        attribute_value: (_) => /[^<>"'=\s]+/,

        // An entity can be named, numeric (decimal), or numeric (hexacecimal). The
        // longest entity name is 29 characters long, and the HTML spec says that
        // no more will ever be added.
        entity: (_) => /&(#([xX][0-9a-fA-F]{1,6}|[0-9]{1,5})|[A-Za-z]{1,30});?/,

        substitution: (_) => /%([\w\-]*;?|%)/,

        quoted_attribute_value: ($) =>
            choice(
                seq("'", optional(alias(/[^']+/, $.attribute_value)), "'"),
                seq('"', optional(alias(/[^"]+/, $.attribute_value)), '"'),
            ),

        text: (_) => /\s*[^<>&%\{]*[^<>&%\{\s][^<>%&\{]*\s*/,
    },
});
