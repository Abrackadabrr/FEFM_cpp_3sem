// Таков интерфейс базового класса std::exception

class exception
{
  public:
    exception() noexcept { }
    virtual ~exception() noexcept;
    exception(const exception&) = default;
    exception& operator=(const exception&) = default;
    exception(exception&&) = default;
    exception& operator=(exception&&) = default;

    /** Returns a C-style character string describing the general cause
     *  of the current error.  */
    virtual const char* what() const noexcept;
};

// Важное замечание -- это аннтоация noexcept
// Аннотируя метод через noexcept мы говорим: 
// "мамой клянусь, что исключение не вылетит"

// Методы, аннонтированные noexcept не содержат внутри себя
// скрытой "логики обработки с исключениями".
// В этом смысле все методы, которые можно аннотировать как noexcept 
// нужно аннотировать как noexcept, поскольку это
// помогает компилятору оптимизировать код.

// Как именно он это делает -- мы не знаем, поэтому это звучит
// как рецепт, которым следует пользоваться. 