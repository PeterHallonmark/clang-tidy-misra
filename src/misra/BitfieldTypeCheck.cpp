//===--- BitfieldTypeCheck.cpp - clang-tidy -------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "BitfieldTypeCheck.h"
#include "clang/AST/Decl.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang::tidy::misra {

// static bool isCompliantBitFieldType(QualType Type, const LangOptions
// &LangOpts);

void BitfieldTypeCheck::registerMatchers(MatchFinder *Finder) {
  if (!getLangOpts().C99) {
    Finder->addMatcher(
        fieldDecl(allOf(isBitField(), hasType(hasCanonicalType(anyOf(
                                          isInteger(), isUnsignedInteger())))))
            .bind("bitField"),
        this);
  } else {
    Finder->addMatcher(
        fieldDecl(allOf(isBitField(),
                        hasType(hasCanonicalType(anyOf(
                            isInteger(), isUnsignedInteger(), booleanType())))))
            .bind("bitField"),
        this);
  }
}

void BitfieldTypeCheck::check(const MatchFinder::MatchResult &Result) {

  const auto *MatchedBitField = Result.Nodes.getNodeAs<FieldDecl>("bitField");

  if (!MatchedBitField) {
    return;
  }
}

} // namespace clang::tidy::misra
