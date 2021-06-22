
all: clean
	latexmk -f -synctex=1 -interaction=nonstopmode --shell-escape main.tex

clean:
	rm -rf *.aux *.log *.out *fls *.fdb_latexmk *.synctex.gz *.bcf *.bbl *.blg *.toc *.run.xml *.dvi

clean_all: clean
	rm -rf *.pdf