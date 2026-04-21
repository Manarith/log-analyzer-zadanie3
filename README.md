# log-analyzer-zadanie3

## Build i uruchomienie (Windows)

### Wymagania
- Visual Studio (Desktop development with C++)
- Python + Conan
- CMake

---

### Kroki

1. Otwórz:
Developer Command Prompt for VS

2. Przejdź do katalogu projektu:
cd ścieżka\do\projektu

3. Pobierz zależności:
conan profile detect --force
conan install . --output-folder=build --build=missing

4. Zbuduj projekt:
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=generators/conan_toolchain.cmake
cmake --build . --config Release

---

### Uruchomienie aplikacji

cd build\Release
main.exe

Upewnij się, że plik `logs.txt` znajduje się w tym samym katalogu.

---

### Uruchomienie testów

ctest -C Release