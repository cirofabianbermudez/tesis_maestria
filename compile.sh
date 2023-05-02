echo "--------------------"
echo "COMPILACIÓN DE TESIS"
echo "--------------------"
echo "1. Iniciando . . ."
latex main.tex > logs.txt
echo "2. Primera compilacion terminada . . ."
bibtex main >> logs.txt
echo "3. BibTeX compilado correctamente . . ."
makeglossaries main >> logs.txt
echo "4. Glosarios compilado correctamente  . . ."
latex main.tex >> logs.txt
echo "5. Segunda compilacion terminada . . ."
pdflatex main.tex >> logs.txt
echo "6. Generando PDF . . ."
rm *.aux *.toc *.lol *.lot *.lof *.ist *.glo *.glg *.gls *.log *.bbl *.out *.dvi *.blg >> logs.txt
echo "7. Eliminando archivos temporales . . ."
echo "8. Proceso terminado . . ."
# read -p "7. Presiona [Enter] para salir . . ."
# sleep 0.5
