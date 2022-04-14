.PHONY=all clean

all:
	pdflatex -shell-escape main.tex
	biber main
	pdflatex -shell-escape main.tex
	
clean:
	rm -rf `ls -p | grep -v "main.tex\|abs.tex\|intro.tex\|related.tex\|preliminary.tex\|proposed.tex\|anb.tex\|conclusion.tex\|main.bib\|main.pdf\|Makefile\|lib/\|src/"`