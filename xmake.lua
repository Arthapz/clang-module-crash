set_policy("build.c++.modules.std", false)

target("Foo")
    set_languages("c++latest")
    add_files("src/*.mpp", "src/*.cpp")
