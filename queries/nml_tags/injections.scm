((comment) @injection.content
  (#set! injection.language "comment"))

; <style>...</style>
; <style blocking> ...</style>
; Add "lang" to predicate check so that vue/svelte can inherit this
; without having this element being captured twice
((style_element
  (start_tag) @_no_type_lang
  (raw_text) @injection.content)
  (#not-lua-match? @_no_type_lang "%slang%s*=")
  (#not-lua-match? @_no_type_lang "%stype%s*=")
  (#set! injection.language "ncss"))

((style_element
  (start_tag
    (attribute
      (attribute_name) @_type
      (quoted_attribute_value
        (attribute_value) @_ncss)))
  (raw_text) @injection.content)
  (#eq? @_type "type")
  (#eq? @_ncss "text/ncss")
  (#set! injection.language "ncss"))

; <script>...</script>
; <script defer>...</script>
((script_element
  (start_tag) @_no_type_lang
  (raw_text) @injection.content)
  ; (#not-lua-match? @_no_type_lang "%slang%s*=")
  ; (#not-lua-match? @_no_type_lang "%stype%s*=")
  (#set! injection.language "lua"))

; <script type="mimetype-or-well-known-script-type">
(script_element
  (start_tag
    (attribute
      (attribute_name) @_attr
      (#eq? @_attr "type")
      (quoted_attribute_value
        (attribute_value) @_type)))
  (raw_text) @injection.content
  (#set-lang-from-mimetype! @_type))

; <a style="/* ncss */">
((attribute
  (attribute_name) @_attr
  (quoted_attribute_value
    (attribute_value) @injection.content))
  (#eq? @_attr "style")
  (#set! injection.language "ncss"))

; lit-html style template interpolation
; <a @click=${e => console.log(e)}>
; <a @click="${e => console.log(e)}">
((attribute
  (quoted_attribute_value
    (attribute_value) @injection.content))
  (#lua-match? @injection.content "%${")
  (#offset! @injection.content 0 2 0 -1)
  (#set! injection.language "lua"))

((attribute
  (attribute_value) @injection.content)
  (#lua-match? @injection.content "%${")
  (#offset! @injection.content 0 2 0 -2)
  (#set! injection.language "lua"))

; <input pattern="[0-9]"> or <input pattern=[0-9]>
(element
  (_
    (tag_name) @_tagname
    (#eq? @_tagname "input")
    (attribute
      (attribute_name) @_attr
      [
        (quoted_attribute_value
          (attribute_value) @injection.content)
        (attribute_value) @injection.content
      ]
      (#eq? @_attr "pattern"))
    (#set! injection.language "regex")))

; <input type="checkbox" onchange="this.closest('form').elements.output.value = this.checked">
(attribute
  (attribute_name) @_name
  (#lua-match? @_name "^on[a-z]+$")
  (quoted_attribute_value
    (attribute_value) @injection.content)
  (#set! injection.language "lua"))
