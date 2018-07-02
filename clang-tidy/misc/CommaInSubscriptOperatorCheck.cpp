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
  // FIXME: Add matchers.
    Finder->addMatcher(
                arraySubscriptExpr(
                    has(binaryOperator(hasOperatorName(",")).bind("expr"))
                    ).bind("op")

                , this
                );
}

void CommaInSubscriptOperatorCheck::check(const MatchFinder::MatchResult &Result) {
  // FIXME: Add callback implementation.
  const ArraySubscriptExpr* op = Result.Nodes.getNodeAs<clang::ArraySubscriptExpr>("op");

  SourceRange range(op->getLocStart(),
                             op->getLocEnd());
  StringRef text = Lexer::getSourceText(CharSourceRange::getTokenRange(range), *Result.SourceManager,
                                        Result.Context->getLangOpts());
  diag(op->getLocStart(), "comma in %0") <<  text;
}

} // namespace misc
} // namespace tidy
} // namespace clang
