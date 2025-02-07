# Brainfuck Interpreter
## Интерпретатор написанный на C++ для brainfuck

## Установка:
1. Скопируйте репозиторий:
```sh
git clone https://github.com/dimabreus/Brainfuck-interpreter.git
```
2. Скомпилируйте программу:
```sh
g++ main.cpp -o brainFuck
```
> [!NOTE]
> Если вы компилируйте программу для ОС Windows, то вы должны добавить флаг `-static`

### Запуск программы:

## Режим первый (Мгновенный интепретатор):
```sh
./brainfuck
```
```sh
File not specified. Instant interpreter mode enabled.
(Enter BrainFuck code)
(Ctrl+D to interpret and exit):

> (Сюды код)
```
> [!IMPORTANT]
> Для интепретации надо нажать Enter, а потом Ctrl+D

## Режим второй (Интепретация из файла .bf):
```sh
./brainfuck <FileName .bf>
```
Пример:
```sh
./brainfuck file.bf
```
