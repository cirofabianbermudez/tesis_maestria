echo "--------------------"
echo "COMPILACIÓN DE TESIS"
echo "--------------------"
echo "1. Iniciando . . ."
latex main.tex > logs.txt
echo "2. Primera compilacion terminada . . ."
bibtex main >> logs.txt
echo "3. BibTeX compilado correctamente . . ."
makeglossaries main >> logs.tex
echo "3. Glosarios compilado correctamente  . . ."
latex main.tex >> logs.txt
echo "4. Segunda compilacion terminada . . ."
pdflatex main.tex >> logs.txt
echo "5. Generando PDF . . ."
rm *.aux *.toc *.lol *.lot *.lof *.ist *.glo *.log *.bbl *.out *.dvi *.blg >> logs.txt
echo "5. Eliminando archivos temporales . . ."
echo "6. Proceso terminado . . ."
# read -p "7. Presiona [Enter] para salir . . ."
# sleep 0.5
