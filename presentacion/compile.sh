echo "--------------------"
echo "COMPILACIÓN DE PRESENTACIÖN"
echo "--------------------"
echo "1. Iniciando . . ."
latex main.tex > logs.txt
echo "2. Primera compilacion terminada . . ."
bibtex main >> logs.txt
echo "3. BibTeX compilado correctamente . . ."
latex main.tex >> logs.txt
echo "4. Segunda compilacion terminada . . ."
pdflatex main.tex >> logs.txt
echo "5. Generando PDF . . ."
rm *.aux *.toc *.lol *.lot *.lof *.ist *.glo *.glg *.gls *.log *.bbl *.out *.dvi *.blg *.nav *.snm >> logs.txt
echo "5. Eliminando archivos temporales . . ."
echo "6. Proceso terminado . . ."
# read -p "7. Presiona [Enter] para salir . . ."
# sleep 0.5
