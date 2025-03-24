```
$ rm -rf .xmake build; xmake f --toolchain=llvm --runtimes="c++_shared" --sdk=/opt/llvm-git/; xmake b -vD | save -f repro.txt
checking for flags (-std=c++26) ... ok
> clang "-std=c++26" "-Qunused-arguments" "-m64"
[  0%]: <Foo> generating.module.deps src/Foo.mpp
checking for /opt/llvm-git/bin/clang-scan-deps ... ok
/opt/llvm-git/bin/clang-scan-deps --format=p1689 -- /opt/llvm-git/bin/clang -x c++ -c src/Foo.mpp -o build/.objs/Foo/linux/x86_64/release/src/Foo.mpp.o -Qunused-arguments -m64 -std=c++26 -stdlib=libc++ -cxx-isystem/opt/llvm-git/include/c++/v1
[  0%]: <Foo> generating.module.deps src/main.cpp
/opt/llvm-git/bin/clang-scan-deps --format=p1689 -- /opt/llvm-git/bin/clang -x c++ -c src/main.cpp -o build/.objs/Foo/linux/x86_64/release/src/main.cpp.o -Qunused-arguments -m64 -std=c++26 -stdlib=libc++ -cxx-isystem/opt/llvm-git/include/c++/v1
[ 42%]: <Foo> compiling.module.release Foo
checking for flags (clang_module_output) ... ok
> clang "-fmodule-output=" "-Qunused-arguments" "-m64"
/opt/llvm-git/bin/clang -c -Qunused-arguments -m64 -std=c++26 -stdlib=libc++ -cxx-isystem/opt/llvm-git/include/c++/v1 -x c++-module -fmodule-output=build/.gens/Foo/linux/x86_64/release/rules/bmi/cache/modules/f55c7a20/Foo.pcm -o build/.objs/Foo/linux/x86_64/release/src/Foo.mpp.o src/Foo.mpp
checking for flags (clang_module_file) ... ok
> clang "-fmodule-file=/tmp/.xmake1000/250324/_1321E3AD72F0462088DFE9F9420E0040.pcm" "-Qunused-arguments" "-m64"
[ 71%]: compiling.release src/main.cpp
/opt/llvm-git/bin/clang -c -Qunused-arguments -m64 -std=c++26 -stdlib=libc++ -cxx-isystem/opt/llvm-git/include/c++/v1 -fmodule-file=Foo=build/.gens/Foo/linux/x86_64/release/rules/bmi/cache/modules/f55c7a20/Foo.pcm -o build/.objs/Foo/linux/x86_64/release/src/main.cpp.o src/main.cpp
checking for flags (-MMD -MF) ... ok
> clang "-MMD" "-MF" "/dev/null" "-Qunused-arguments" "-m64"
error: @programdir/core/main.lua:329: @programdir/actions/build/main.lua:146: @programdir/modules/async/runjobs.lua:330: @programdir/modules/private/action/build/object.lua:100: @programdir/modules/core/tools/gcc.lua:980: clang: /home/arthapz/Development/AUR/llvm-git/src/llvm-project/clang/include/clang/AST/DeclCXX.h:2648: void clang::CXXConstructorDecl::setExplicitSpecifier(ExplicitSpecifier): Assertion `(!ES.getExpr() || CXXConstructorDeclBits.HasTrailingExplicitSpecifier) && "cannot set this explicit specifier. no trail-allocated space for " "explicit"' failed.
PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed source, and associated run script.
Stack dump:
0.	Program arguments: /opt/llvm-git/bin/clang -c -Qunused-arguments -m64 -std=c++26 -stdlib=libc++ -cxx-isystem/opt/llvm-git/include/c++/v1 -fmodule-file=Foo=build/.gens/Foo/linux/x86_64/release/rules/bmi/cache/modules/f55c7a20/Foo.pcm -MMD -MF /tmp/.xmake1000/250324/_A98165A13FB04C2088AA6EA33AA9B360 -o build/.objs/Foo/linux/x86_64/release/src/main.cpp.o src/main.cpp
1.	src/main.cpp:8:24: current parser token ';'
2.	src/main.cpp:7:12: parsing function body 'main'
3.	src/main.cpp:7:12: in compound statement ('{}')
4.	/home/arthapz/Development/Repos/crash-clang/src/Foo.mpp:14:7: instantiating class definition 'Foo<Bar>'
 #0 0x000079aaa58ab98a llvm::sys::PrintStackTrace(llvm::raw_ostream&, int) (/opt/llvm-git/bin/../lib/libLLVM.so.21.0+0xaab98a)
 #1 0x000079aaa58a9262 llvm::sys::RunSignalHandlers() (/opt/llvm-git/bin/../lib/libLLVM.so.21.0+0xaa9262)
 #2 0x000079aaa57da961 CrashRecoverySignalHandler(int) CrashRecoveryContext.cpp:0:0
 #3 0x000079aaa484bcd0 (/usr/lib/libc.so.6+0x3dcd0)
 #4 0x000079aaa48a5624 (/usr/lib/libc.so.6+0x97624)
 #5 0x000079aaa484bba0 raise (/usr/lib/libc.so.6+0x3dba0)
 #6 0x000079aaa4833582 abort (/usr/lib/libc.so.6+0x25582)
 #7 0x000079aaa48334eb __assert_perror_fail (/usr/lib/libc.so.6+0x254eb)
 #8 0x000079aaab389755 clang::CXXConstructorDecl::setExplicitSpecifier(clang::ExplicitSpecifier) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0xb89755)
 #9 0x000079aaad12f1f6 clang::ASTDeclReader::VisitCXXConstructorDecl(clang::CXXConstructorDecl*) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x292f1f6)
#10 0x000079aaad11f633 clang::ASTDeclReader::Visit(clang::Decl*) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x291f633)
#11 0x000079aaaae78f31 clang::StackExhaustionHandler::runWithSufficientStackSpace(clang::SourceLocation, llvm::function_ref<void ()>) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x678f31)
#12 0x000079aaad1483c8 clang::ASTReader::ReadDeclRecord(clang::GlobalDeclID) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x29483c8)
#13 0x000079aaad0c8c29 clang::ASTReader::GetDecl(clang::GlobalDeclID) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x28c8c29)
#14 0x000079aaad12faea clang::ASTDeclReader::VisitTemplateDecl(clang::TemplateDecl*) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x292faea)
#15 0x000079aaad1306b0 clang::ASTDeclReader::VisitRedeclarableTemplateDecl(clang::RedeclarableTemplateDecl*) ASTReaderDecl.cpp:0:0
#16 0x000079aaad13144f clang::ASTDeclReader::VisitFunctionTemplateDecl(clang::FunctionTemplateDecl*) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x293144f)
#17 0x000079aaad11f633 clang::ASTDeclReader::Visit(clang::Decl*) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x291f633)
#18 0x000079aaaae78f31 clang::StackExhaustionHandler::runWithSufficientStackSpace(clang::SourceLocation, llvm::function_ref<void ()>) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x678f31)
#19 0x000079aaad1483c8 clang::ASTReader::ReadDeclRecord(clang::GlobalDeclID) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x29483c8)
#20 0x000079aaad0c8c29 clang::ASTReader::GetDecl(clang::GlobalDeclID) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x28c8c29)
#21 0x000079aaad14c9c8 clang::ASTReader::loadPendingDeclChain(clang::Decl*, unsigned long) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x294c9c8)
#22 0x000079aaad0e2c83 clang::ASTReader::finishPendingActions() (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x28e2c83)
#23 0x000079aaad0e9770 clang::ASTReader::FinishedDeserializing() (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x28e9770)
#24 0x000079aaab3788ca clang::DeclContext::LoadLexicalDeclsFromExternalStorage() const (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0xb788ca)
#25 0x000079aaab378eb6 clang::DeclContext::decls_begin() const (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0xb78eb6)
#26 0x000079aaac4f6bb5 clang::Sema::InstantiateClass(clang::SourceLocation, clang::CXXRecordDecl*, clang::CXXRecordDecl*, clang::MultiLevelTemplateArgumentList const&, clang::TemplateSpecializationKind, bool) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x1cf6bb5)
#27 0x000079aaac4f937a clang::Sema::InstantiateClassTemplateSpecialization(clang::SourceLocation, clang::ClassTemplateSpecializationDecl*, clang::TemplateSpecializationKind, bool, bool) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x1cf937a)
#28 0x000079aaac60c8d2 void llvm::function_ref<void ()>::callback_fn<clang::Sema::RequireCompleteTypeImpl(clang::SourceLocation, clang::QualType, clang::Sema::CompleteTypeKind, clang::Sema::TypeDiagnoser*)::$_0>(long) SemaType.cpp:0:0
#29 0x000079aaaae78f31 clang::StackExhaustionHandler::runWithSufficientStackSpace(clang::SourceLocation, llvm::function_ref<void ()>) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x678f31)
#30 0x000079aaac5f3928 clang::Sema::RequireCompleteTypeImpl(clang::SourceLocation, clang::QualType, clang::Sema::CompleteTypeKind, clang::Sema::TypeDiagnoser*) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x1df3928)
#31 0x000079aaac5f31c4 clang::Sema::RequireCompleteType(clang::SourceLocation, clang::QualType, clang::Sema::CompleteTypeKind, clang::Sema::TypeDiagnoser&) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x1df31c4)
#32 0x000079aaac0601af clang::Sema::BuildCXXTypeConstructExpr(clang::TypeSourceInfo*, clang::SourceLocation, llvm::MutableArrayRef<clang::Expr*>, clang::SourceLocation, bool) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x18601af)
#33 0x000079aaac05fa1a clang::Sema::ActOnCXXTypeConstructExpr(clang::OpaquePtr<clang::QualType>, clang::SourceLocation, llvm::MutableArrayRef<clang::Expr*>, clang::SourceLocation, bool) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x185fa1a)
#34 0x000079aaab077502 clang::Parser::ParseCXXTypeConstructExpression(clang::DeclSpec const&) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x877502)
#35 0x000079aaab060aaa clang::Parser::ParseCastExpression(clang::Parser::CastParseKind, bool, bool&, clang::Parser::TypeCastState, bool, bool*) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x860aaa)
#36 0x000079aaab060522 clang::Parser::ParseCastExpression(clang::Parser::CastParseKind, bool, bool&, clang::Parser::TypeCastState, bool, bool*) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x860522)
#37 0x000079aaab05b216 clang::Parser::ParseAssignmentExpression(clang::Parser::TypeCastState) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x85b216)
#38 0x000079aaab0222ab clang::Parser::ParseDeclarationAfterDeclaratorAndAttributes(clang::Declarator&, clang::Parser::ParsedTemplateInfo const&, clang::Parser::ForRangeInit*) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x8222ab)
#39 0x000079aaab01f4d2 clang::Parser::ParseDeclGroup(clang::ParsingDeclSpec&, clang::DeclaratorContext, clang::ParsedAttributes&, clang::Parser::ParsedTemplateInfo&, clang::SourceLocation*, clang::Parser::ForRangeInit*) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x81f4d2)
#40 0x000079aaab01e496 clang::Parser::ParseSimpleDeclaration(clang::DeclaratorContext, clang::SourceLocation&, clang::ParsedAttributes&, clang::ParsedAttributes&, bool, clang::Parser::ForRangeInit*, clang::SourceLocation*) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x81e496)
#41 0x000079aaab01dccc clang::Parser::ParseDeclaration(clang::DeclaratorContext, clang::SourceLocation&, clang::ParsedAttributes&, clang::ParsedAttributes&, clang::SourceLocation*) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x81dccc)
#42 0x000079aaab0cbcdd clang::Parser::ParseStatementOrDeclarationAfterAttributes(llvm::SmallVector<clang::Stmt*, 24u>&, clang::Parser::ParsedStmtContext, clang::SourceLocation*, clang::ParsedAttributes&, clang::ParsedAttributes&) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x8cbcdd)
#43 0x000079aaab0cb3bc clang::Parser::ParseStatementOrDeclaration(llvm::SmallVector<clang::Stmt*, 24u>&, clang::Parser::ParsedStmtContext, clang::SourceLocation*) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x8cb3bc)
#44 0x000079aaab0d5902 clang::Parser::ParseCompoundStatementBody(bool) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x8d5902)
#45 0x000079aaab0d6614 clang::Parser::ParseFunctionStatementBody(clang::Decl*, clang::Parser::ParseScope&) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x8d6614)
#46 0x000079aaab0f25da clang::Parser::ParseFunctionDefinition(clang::ParsingDeclarator&, clang::Parser::ParsedTemplateInfo const&, clang::Parser::LateParsedAttrList*) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x8f25da)
#47 0x000079aaab020541 clang::Parser::ParseDeclGroup(clang::ParsingDeclSpec&, clang::DeclaratorContext, clang::ParsedAttributes&, clang::Parser::ParsedTemplateInfo&, clang::SourceLocation*, clang::Parser::ForRangeInit*) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x820541)
#48 0x000079aaab0f1711 clang::Parser::ParseDeclOrFunctionDefInternal(clang::ParsedAttributes&, clang::ParsedAttributes&, clang::ParsingDeclSpec&, clang::AccessSpecifier) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x8f1711)
#49 0x000079aaab0f0f05 clang::Parser::ParseDeclarationOrFunctionDefinition(clang::ParsedAttributes&, clang::ParsedAttributes&, clang::ParsingDeclSpec*, clang::AccessSpecifier) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x8f0f05)
#50 0x000079aaab0efdf9 clang::Parser::ParseExternalDeclaration(clang::ParsedAttributes&, clang::ParsedAttributes&, clang::ParsingDeclSpec*) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x8efdf9)
#51 0x000079aaab0ee153 clang::Parser::ParseTopLevelDecl(clang::OpaquePtr<clang::DeclGroupRef>&, clang::Sema::ModuleImportState&) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x8ee153)
#52 0x000079aaab00656e clang::ParseAST(clang::Sema&, bool, bool) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x80656e)
#53 0x000079aaad3d24f8 clang::FrontendAction::Execute() (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x2bd24f8)
#54 0x000079aaad33a79d clang::CompilerInstance::ExecuteAction(clang::FrontendAction&) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x2b3a79d)
#55 0x000079aaad46e85d clang::ExecuteCompilerInvocation(clang::CompilerInstance*) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x2c6e85d)
#56 0x0000565c249d945b cc1_main(llvm::ArrayRef<char const*>, char const*, void*) (/opt/llvm-git/bin/clang+0x1245b)
#57 0x0000565c249d54e9 ExecuteCC1Tool(llvm::SmallVectorImpl<char const*>&, llvm::ToolContext const&) driver.cpp:0:0
#58 0x000079aaacef1f6d void llvm::function_ref<void ()>::callback_fn<clang::driver::CC1Command::Execute(llvm::ArrayRef<std::optional<llvm::StringRef>>, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>*, bool*) const::$_0>(long) Job.cpp:0:0
#59 0x000079aaa57da666 llvm::CrashRecoveryContext::RunSafely(llvm::function_ref<void ()>) (/opt/llvm-git/bin/../lib/libLLVM.so.21.0+0x9da666)
#60 0x000079aaacef1798 clang::driver::CC1Command::Execute(llvm::ArrayRef<std::optional<llvm::StringRef>>, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>*, bool*) const (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x26f1798)
#61 0x000079aaaceb197c clang::driver::Compilation::ExecuteCommand(clang::driver::Command const&, clang::driver::Command const*&, bool) const (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x26b197c)
#62 0x000079aaaceb1bc7 clang::driver::Compilation::ExecuteJobs(clang::driver::JobList const&, llvm::SmallVectorImpl<std::pair<int, clang::driver::Command const*>>&, bool) const (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x26b1bc7)
#63 0x000079aaaced0b69 clang::driver::Driver::ExecuteCompilation(clang::driver::Compilation&, llvm::SmallVectorImpl<std::pair<int, clang::driver::Command const*>>&) (/opt/llvm-git/bin/../lib/libclang-cpp.so.21.0+0x26d0b69)
#64 0x0000565c249d4d47 clang_main(int, char**, llvm::ToolContext const&) (/opt/llvm-git/bin/clang+0xdd47)
#65 0x0000565c249e445a main (/opt/llvm-git/bin/clang+0x1d45a)
#66 0x000079aaa4835488 (/usr/lib/libc.so.6+0x27488)
#67 0x000079aaa483554c __libc_start_main (/usr/lib/libc.so.6+0x2754c)
#68 0x0000565c249d2e55 _start (/opt/llvm-git/bin/clang+0xbe55)
clang: error: clang frontend command failed with exit code 134 (use -v to see invocation)
clang version 21.0.0 (/home/arthapz/Development/AUR/llvm-git/llvm-project ed022d93b2fbfe52b7bdee786aa5cc49fa2323c4)
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /opt/llvm-git/bin
Build config: +assertions
clang: note: diagnostic msg: 
********************
PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT:
Preprocessed source(s) and associated run script(s) are located at:
clang: note: diagnostic msg: /tmp/main-b8f808.cpp
clang: note: diagnostic msg: /tmp/main-b8f808.sh
clang: note: diagnostic msg: 
********************
stack traceback:
    [C]: in function 'error'
    [@programdir/core/base/os.lua:1075]:
    [@programdir/modules/core/tools/gcc.lua:980]: in function 'catch'
    [@programdir/core/sandbox/modules/try.lua:123]: in function 'try'
    [@programdir/modules/core/tools/gcc.lua:924]:
    [C]: in function 'xpcall'
    [@programdir/core/base/utils.lua:246]:
    [@programdir/core/tool/compiler.lua:288]: in function 'compile'
    [@programdir/modules/private/action/build/object.lua:100]: in function 'script'
    [@programdir/modules/private/action/build/object.lua:131]: in function 'build_object'
    [@programdir/modules/private/action/build/object.lua:156]: in function 'jobfunc'
    [@programdir/modules/async/runjobs.lua:246]:
    [C]: in function 'xpcall'
    [@programdir/core/base/utils.lua:246]: in function 'trycall'
    [@programdir/core/sandbox/modules/try.lua:117]: in function 'try'
    [@programdir/modules/async/runjobs.lua:229]: in function 'cotask'
    [@programdir/core/base/scheduler.lua:406]:

stack traceback:
	[C]: in function 'error'
	@programdir/core/base/os.lua:1075: in function 'os.raiselevel'
	(...tail calls...)
	@programdir/core/main.lua:329: in upvalue 'cotask'
	@programdir/core/base/scheduler.lua:406: in function <@programdir/core/base/scheduler.lua:399>
```
