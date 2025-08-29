To create a latex file inside termux:
login into distro-
```bash
proot-distro login debian
```
Create a nano file(maths) inside your directory:
```bash
nano maths.tex
```
To save and exit from the nano file use CTRL+O(to save the file), Enter, CTRL+X(to exit from the file)
Run these following commands smoothly to generate the pdf:
```bash
texfot pdflatex maths.tex
pdflatex maths.tex
termux-open maths.pdf
```
