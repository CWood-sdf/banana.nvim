package tree_sitter_banana_nvim_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-banana_nvim"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_banana_nvim.Language())
	if language == nil {
		t.Errorf("Error loading BananaNvim grammar")
	}
}
