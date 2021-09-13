# Documentación tesis de maestría

1. Los programas principales que se utilizaron son:
   1. [TeX Live](http://mirrors.ibiblio.org/CTAN/systems/texlive/Images/): distribución de LaTeX multiplataforma.
   2. [Texmaker](https://www.xm1math.net/texmaker/): editor para LaTeX.
   3. [Inkscape 1.0](https://inkscape.org/release/inkscape-1.0/): software de vectores gráficos.
   4. [TexText](https://textext.github.io/textext/), complemento de Inkscape para renderizar LaTeX.
      - Recomendado instalar [GtkSourceview 3 for Inkscape 1.0 64-bit](https://github.com/textext/gtksourceview-for-inkscape-windows/releases/download/1.0.0/Install-GtkSourceView-3.24-Inkscape-1.0-64bit.exe).
   5. [JabRef](https://www.jabref.org/): gestor de bibliografía para LaTeX.
   6. [Git for windows](https://gitforwindows.org/): control de versiones del proyecto.
   7. [Gnuplot](http://www.gnuplot.info/): graficador de software libre.
   8. [Sumatra PDF](https://www.sumatrapdfreader.org/free-pdf-reader): Lector de pdf gratis y ligero.
   9. [InfranView](https://www.irfanview.com/): visualizador de imágenes.
      - Recomendado instalar [Plugins](https://www.irfanview.com/plugins.htm) para poder visualizar`.eps`.



> **Nota:** JabRef se puede usar de forma portable y utilizando los DOI de los artículos generar automáticamente la referencia.



> **Nota:** En InfraView realizar las siguientes configuraciones para mejor manejo
>
> - `View \ Display options (window mode) \ Do not fit anything`
>
> - `Options \ Properties/Settings \ Browsing/Editing \Do nothing (stop)`
> - `Options \ Properties/Settings \ Browsing/Editing `





2. Se agregó un archivo `.gitignore` para no guardar los `.pdf` de la bibliografía para ahorrar espacio en el repositorio pero se tiene acceso a todos ellos viendo el archivo `bibliogragria.bib`.

3. Para que la bibliografía funcione correctamente es necesario seguir los siguientes pasos:

   1. Compilar normalmente con `F6`.
   2. Compilar la bibliografía dos veces con `F11`.
   3. Compilar normalmente con `F6` una última vez.

   estos pasos se deben seguir cada vez que se añada una nueva entrada a la bibliografía y se cite en el texto, sin embargo para ahorrar tiempo se puede ejecutar el archivo `run_latex_complete.bat` para evitarse ese trabajo.

4. Para la instalación de Vidado 2020.2 se recomienda utilizar la versión de instalador ***"Windows self extracting web installer"*** para ahorrar tiempo y espacio en el disco duro, tiene un tamaño de 246.44  MB, como recomendación realizar la instalación utilizando una conexión por cable ethernet. Se debe seleccionar la versión **Vivado HL Design Edition** ya que esta es la que cuenta con más herramientas de síntesis. 

5. Para poder acceder a los recursos y bibliotecas digitales es necesario conectarse mediante un proxy, para eso hay que seguir los siguientes pasos en Firefox:

   1. Dar clic en `Menú \ Opciones`y navegar hasta la parte inferior donde dice **Configuración de conexión** y dar clic en `Configurar...`
   2. Seleccionar `Configuración manual de proxy` e ingresar los siguientes datos:
      1. Proxy HTTP: `192.100.172.174`
      2. Puerto: `3128`
      3. Marcar `También usar este proxy para HTTPS` y Aceptar
      4. Reiniciar el navegador e ingresar las credenciales del servidor las cuales son las mismas que en el correo institucional.
   3. [Recursos electrónicos INAOE](https://www.inaoep.mx/biblioteca/e-recursos/) desde este link y una vez ingresadas las credenciales correctas se tiene acceso a todos lo recursos.

   

   

