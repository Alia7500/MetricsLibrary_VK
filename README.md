# MetricsLibrary_VK

C++ библиотека для сбора и хранения метрик в текстовом файле.

## Обзор

Эта библиотека предоставляет набор классов для сбора и хранения метрик в текстовом файле. Она позволяет добавлять новые типы метрик без изменения существующего кода и обеспечивает потокобезопасную запись метрик.

## Возможности

*   Сбор метрик различных типов (загрузка CPU, количество HTTP-запросов, использование памяти и т.д.).
*   Запись метрик в текстовый файл с указанием времени и значений.
*   Поддержка добавления новых типов метрик без переписывания реализации.
*   Потокобезопасная запись метрик (в многопоточных приложениях).

## Структура проекта:

.gitignore

README.md: Этот файл (который вы сейчас читаете) содержит описание проекта, инструкции по сборке.

📁MetricsLibrary: Эта папка содержит исходный код библиотеки MetricsLibrary.

    📁include: Эта папка содержит заголовочные файлы библиотеки.
        metric.h: Абстрактный базовый класс для метрик.
        cpu_usage_metric.h: Класс для метрики использования CPU.
        http_request_count_metric.h: Класс для метрики количества HTTP-запросов.
        memory_usage_metric.h: Класс для метрики использования памяти.
        metrics_storage.h: Класс для хранения и записи метрик.
    📁src: Эта папка содержит файлы реализации библиотеки.
        cpu_usage_metric.cpp: Реализация класса CpuUsageMetric.
        http_request_count_metric.cpp: Реализация класса HttpRequestCountMetric.
        memory_usage_metric.cpp: Реализация класса MemoryUsageMetric.
        metrics_storage.cpp: Реализация класса MetricsStorage.
    MetricsLibrary.sln: Файл решения Visual Studio.
    MetricsLibrary.vcxproj: Файл проекта Visual Studio.
    
📁app: Эта папка содержит пример использования библиотеки (консольное приложение).

    main.cpp: Файл main.cpp с примером использования библиотеки.
    app.vcxproj: Файл проекта Visual Studio для приложения.
    app.vcxproj.filters: Файл фильтров Visual Studio для проекта приложения.
    app.vcxproj.user: Файл пользовательских настроек Visual Studio для проекта приложения.
    📄metrics.txt: Файл с примером вывода данных.
    
## Сборка
Для сборки проекта необходима Visual Studio или другая среда разработки C++, поддерживающая создание статических библиотек.
Откройте файл решения MetricsLibrary.sln в Visual Studio.
Выберите нужную конфигурацию (Debug или Release) и платформу (x86 или x64).
Выполните сборку решения (Сборка -> Собрать решение).
