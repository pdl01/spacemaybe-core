Place a TrueType font file named `DejaVuSans.ttf` into this folder so the game can use it for UI text.

Options to get the font:
- Copy from a typical Linux system location:
  cp /usr/share/fonts/truetype/dejavu/DejaVuSans.ttf src/Resources/Fonts/

- Download DejaVu Sans (open-source) from a trusted source and place the TTF here.

After placing the file, rebuild the project:

```bash
mkdir -p build
cd build
cmake ..
cmake --build . -- -j
```

If you prefer, you can also install DejaVu on your system (Debian/Ubuntu):

```bash
sudo apt install fonts-dejavu-core
```

The code will try `Resources/Fonts/DejaVuSans.ttf`, `src/Resources/Fonts/DejaVuSans.ttf`, then `/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf` as fallbacks.
