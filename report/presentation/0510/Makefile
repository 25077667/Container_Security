all:
	pdflatex --shell-escape -synctex=1 -interaction=nonstopmode -file-line-error -recorder secprog.tex
clean:
	rm -f `ls -p | grep -v "/\|secprog.tex\|secprog.pdf\|Makefile\|secprog.bib\|Dockerfile"`
