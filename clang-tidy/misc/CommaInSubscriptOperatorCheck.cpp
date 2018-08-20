//===--- CommaInSubscriptOperatorCheck.cpp - clang-tidy--------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "CommaInSubscriptOperatorCheck.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace misc {

void CommaInSubscriptOperatorCheck::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(stmt(has(binaryOperator(hasOperatorName(",")))).bind("op"),
                     this);
}

void CommaInSubscriptOperatorCheck::check(
    const MatchFinder::MatchResult &Result) {
  const Stmt *op = Result.Nodes.getNodeAs<clang::Stmt>("op");

  SourceRange range(op->getLocStart(), op->getLocEnd());
  StringRef text = Lexer::getSourceText(CharSourceRange::getTokenRange(range),
                                        *Result.SourceManager,
                                        Result.Context->getLangOpts());
  diag(op->getLocStart(),
       "comma expression in " + std::string(op->getStmtClassName()))
      << text;
}

} // namespace misc
} // namespace tidy
} // namespace clang
