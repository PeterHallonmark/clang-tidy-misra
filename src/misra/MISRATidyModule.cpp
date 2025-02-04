//===--- MISRATidyModule.cpp - clang-tidy --------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "../ClangTidy.h"
#include "../ClangTidyModule.h"
#include "../ClangTidyModuleRegistry.h"
#include "../cert/FloatLoopCounter.h"
#include "../misc/NoRecursionCheck.h"
#include "../misc/UnusedParametersCheck.h"
#include "AtoXCheck.h"
#include "AvoidAssignmentInExpressionCheck.h"
#include "AvoidAtomicVoidPointerCheck.h"
#include "AvoidBitfieldsInUnionsCheck.h"
#include "AvoidCommaOperatorCheck.h"
#include "AvoidGotoCheck.h"
#include "AvoidLinesplicingWithinCommentCheck.h"
#include "AvoidNonBooleanConditionCheck.h"
#include "AvoidOctalNumberCheck.h"
#include "AvoidRestrictTypeCheck.h"
#include "AvoidSetjmpHeaderCheck.h"
#include "AvoidSignalHeaderCheck.h"
#include "AvoidSignedSingleBitFieldsCheck.h"
#include "AvoidStdargHeaderCheck.h"
#include "AvoidStdlibMemoryCheck.h"
#include "AvoidStdlibRandCheck.h"
#include "AvoidUndefCheck.h"
#include "AvoidUnionCheck.h"
#include "AvoidstdlibsystemcallCheck.h"
#include "CommentWithinCommentCheck.h"
#include "ExitCheck.h"
#include "ForwardGotoLabelCheck.h"
#include "MissingCompoundCheck.h"
#include "MissingDefaultInSwitchStatementCheck.h"
#include "MissingElseCheck.h"
#include "MissingbreakinswitchCheck.h"
#include "MissingreturnvaluehandlingCheck.h"
#include "MultipleReturnStmtCheck.h"
#include "NoreturnvoidCheck.h"
#include "StaticInlineCheck.h"
#include "UnstructuredcaseCheck.h"
#include "UnusedlabelCheck.h"
#include "WrongorderdefaultinswitchstatementCheck.h"

// using namespace clang::ast_matchers;

namespace clang::tidy {
namespace misra {

class MISRAC2023Module : public ClangTidyModule {
public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {

    /* 1. Standard environment */
    /* 1.1 */
    /* 1.2 */
    /* 1.3 */
    /* 1.4 */
    /* 1.5 */

    /* Unused code */
    /* 2.1 */
    /* 2.2 */
    /* 2.3 */
    /* 2.4 */
    /* 2.5 */
    CheckFactories.registerCheck<UnusedlabelCheck>("misra-c2023-adv-2.6");
    CheckFactories.registerCheck<misc::UnusedParametersCheck>(
        "misra-c2023-adv-2.7");
    /* 2.8 */

    /* 3. Comments */
    /* ------------------------------------------------------------- */
    CheckFactories.registerCheck<CommentWithinCommentCheck>(
        "misra-c2023-req-3.1");
    CheckFactories.registerCheck<AvoidLinesplicingWithinCommentCheck>(
        "misra-c2023-req-3.2");

    /* 4. Character sets and lexical conventions */
    /* ------------------------------------------------------------- */
    /* req-4.2: -Wtrigraphs */

    /* 5. Identifiers */
    /* ------------------------------------------------------------- */

    /* 6. Types */
    /* ------------------------------------------------------------- */
    /* 6.1. TODO */
    CheckFactories.registerCheck<AvoidSignedSingleBitFieldsCheck>(
        "misra-c2023-req-6.2");
    CheckFactories.registerCheck<AvoidBitfieldsInUnionsCheck>(
        "misra-c2023-req-6.3");

    /* 7. Literals and constants */
    /* ------------------------------------------------------------- */
    CheckFactories.registerCheck<AvoidOctalNumberCheck>("misra-c2023-req-7.1");

    /* 8. Declarations and definitions */
    /* ------------------------------------------------------------- */
    CheckFactories.registerCheck<StaticInlineCheck>("misra-c2023-req-8.10");
    /* 8.11 m varDecl(allOf(hasType(arrayType(incompleteArrayType())),
     * hasExternalFormalLinkage())) */
    CheckFactories.registerCheck<AvoidRestrictTypeCheck>(
        "misra-c2023-req-8.14");

    /* 9. Initialization */
    /* ------------------------------------------------------------- */

    /* 10. The essential type model */
    /* ------------------------------------------------------------- */

    /* 11. Pointer type conversions */
    /* ------------------------------------------------------------- */
    CheckFactories.registerCheck<MissingbreakinswitchCheck>(
        "misra-c2023-req-11.2");
    /* 11.10: Diagnostic error */

    /* 12. Expressions */
    /* ------------------------------------------------------------- */
    CheckFactories.registerCheck<AvoidCommaOperatorCheck>(
        "misra-c2023-adv-12.3");

    /* 13. Side effects */
    /* ------------------------------------------------------------- */
    CheckFactories.registerCheck<AvoidAssignmentInExpressionCheck>(
        "misra-c2023-adv-13.4");

    /* 14. Control statement expressions */
    /* ------------------------------------------------------------- */
    CheckFactories.registerCheck<cert::FloatLoopCounter>(
        "misra-c2023-req-14.1");
    CheckFactories.registerCheck<AvoidNonBooleanConditionCheck>(
        "misra-c2023-req-14.4");

    /* 15. Control Flow */
    /* ------------------------------------------------------------- */
    CheckFactories.registerCheck<AvoidGotoCheck>("misra-c2023-adv-15.1");
    CheckFactories.registerCheck<ForwardGotoLabelCheck>("misra-c2023-req-15.2");
    CheckFactories.registerCheck<MultipleReturnStmtCheck>(
        "misra-c2023-adv-15.5");
    CheckFactories.registerCheck<MissingCompoundCheck>("misra-c2023-req-15.6");
    CheckFactories.registerCheck<MissingElseCheck>("misra-c2023-req-15.7");

    /* 16. Switch Statements */
    /* ------------------------------------------------------------- */
    CheckFactories.registerCheck<UnstructuredcaseCheck>("misra-c2023-req-16.2");
    CheckFactories.registerCheck<MissingDefaultInSwitchStatementCheck>(
        "misra-c2023-req-16.4");
    CheckFactories.registerCheck<WrongorderdefaultinswitchstatementCheck>(
        "misra-c2023-req-16.5");
    /* req-16.7: -Wswitch-bool */

    /* 16.2 Inspiration: m
     * caseStmt(unless(hasParent(compoundStmt(hasParent(switchStmt()))))) */

    /* 17. Functions */
    /* ------------------------------------------------------------- */
    CheckFactories.registerCheck<AvoidStdargHeaderCheck>(
        "misra-c2023-req-17.1");
    CheckFactories.registerCheck<misc::NoRecursionCheck>(
        "misra-c2023-req-17.2");
    CheckFactories.registerCheck<MissingreturnvaluehandlingCheck>(
        "misra-c2023-req-17.7");
    CheckFactories.registerCheck<NoreturnvoidCheck>("misra-c2023-req-17.10");
    /* 18. Pointers and arrays */
    /* ------------------------------------------------------------- */
    /* 18.7 m Inspiration:
       varDecl(allOf(hasType(arrayType(incompleteArrayType())))) 18.8 m
       Inspiration:  varDecl(allOf(hasType(arrayType(incompleteArrayType()))))
*/

    /* 19. Overlapping Storage */
    /* ------------------------------------------------------------- */
    CheckFactories.registerCheck<AvoidUnionCheck>("misra-c2023-adv-19.2");

    /* 20. Preprocessing directives */
    /* ------------------------------------------------------------- */
    /* 20.3 clang-native: clang-diagnostic-error */
    CheckFactories.registerCheck<AvoidUndefCheck>("misra-c2023-adv-20.5");

    /* 21. Standard libraries */
    /* ------------------------------------------------------------- */
    // CheckFactories.registerCheck<AvoidStdlibMemoryCheck>(
    //     "misra-c2023-req-21.3");
    CheckFactories.registerCheck<AvoidSetjmpHeaderCheck>(
        "misra-c2023-req-21.4");
    CheckFactories.registerCheck<AvoidSignalHeaderCheck>(
        "misra-c2023-req-21.5");
    CheckFactories.registerCheck<AtoXCheck>("misra-c2023-req-21.7");
    CheckFactories.registerCheck<ExitCheck>("misra-c2023-req-21.8");

    CheckFactories.registerCheck<AvoidstdlibsystemcallCheck>(
        "misra-c2023-req-21.21");
    CheckFactories.registerCheck<AvoidStdlibRandCheck>("misra-c2023-req-21.24");

    // CheckFactories.registerCheck<FoobarCheck>(
    //     "misra-foobar");

    /* TODO:
          Switch statment without default
          m switchStmt(forEachSwitchCase(unless(defaultStmt())))

          Switch without break
          m switchStmt(forEachSwitchCase(unless(has(breakStmt()))))


         8.10
         8.11
         8.14
        15.7
        16.3
        16.4
        16.6


   */
  }
};

class MISRAC2012Module : public ClangTidyModule {
public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<AvoidGotoCheck>("misra-c2012-adv-15.1");
    CheckFactories.registerCheck<MissingCompoundCheck>("misra-c2012-req-15.6");
  }
};

} // namespace misra

// Register the MISRA C2023 Module using this statically initialized variable.
static ClangTidyModuleRegistry::Add<misra::MISRAC2023Module>
    X("misra-c2023-module", "Adds MISRA C 2023 lint checks.");

// Register the MISRA C2023 Module using this statically initialized variable.
static ClangTidyModuleRegistry::Add<misra::MISRAC2012Module>
    Y("misra-c2012-module", "Adds MISRA C 2012 lint checks.");

// This anchor is used to force the linker to link in the generated object file
// and thus register the MisraModule.
volatile int MISRAModuleAnchorSource = 0;

} // namespace clang::tidy
