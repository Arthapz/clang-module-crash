import Foo;

struct Bar {
  
};

int main() {
  std::println("{}", __clang_version__);
  auto foo = Foo<Bar>{};
  return 0;
}
