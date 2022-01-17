all:
	latexmk -pdflatex -file-line-error -interaction=nonstopmode -synctex=1 -f report.tex
clean:
	rm -f *-blx.bib
	rm -f *.aux
	rm -f *.bbl
	rm -f *.bcf
	rm -f *.blg
	rm -f *.fdb*
	rm -f *.fls
	rm -f *.log
	rm -f *.run.xml
	rm -f *.synctex*
	rm -f *.toc
	rm -f *.xdv
	rm -f *.out.ps
clean_all: clean
	rm -f main.pdf