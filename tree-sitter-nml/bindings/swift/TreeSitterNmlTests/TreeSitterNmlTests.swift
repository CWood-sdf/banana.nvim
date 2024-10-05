import XCTest
import SwiftTreeSitter
import TreeSitterNml

final class TreeSitterNmlTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_nml())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Nml grammar")
    }
}
