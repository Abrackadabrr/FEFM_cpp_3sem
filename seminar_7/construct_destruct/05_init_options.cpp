struct MyClass {
	int a;
	int b;
	int c;

	MyClass(): c(5), b(5), a(1) {}
	// порядок инициализации согласлован не со списком инициализации,
	// а с порядок объявления полей
	// в данном кейсе в любом случае будет порядок a, b, c
}

struct MyClass {
// определение по умолчанию прямо во время объявления поля 
	int a = 1;
	MyClass() {}  // аналогичен MyCalss(): a(1) {}
		      // то есть значение 1 затаскивается внутрь списков инициализации
}
