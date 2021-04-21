all:
	pdflatex  -synctex=1 -interaction=nonstopmode -file-line-error -recorder mem.tex
clean:
	rm -f `ls -p | grep -v "/\|mem.tex\|mem.pdf\|Makefile"`
