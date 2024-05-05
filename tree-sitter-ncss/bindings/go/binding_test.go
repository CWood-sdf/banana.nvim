package tree_sitter_css_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-css"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_css.Language())
	if language == nil {
		t.Errorf("Error loading CSS grammar")
	}
}
