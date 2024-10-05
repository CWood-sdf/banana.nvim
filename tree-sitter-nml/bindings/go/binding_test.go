package tree_sitter_nml_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_nml "github.com/tree-sitter/tree-sitter-nml/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_nml.Language())
	if language == nil {
		t.Errorf("Error loading Nml grammar")
	}
}
