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
   10. [Vivado 2020.2](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vivado-design-tools/2020-2.html): herramienta para trabajar con FPGAs de Xilinx.
       * Recomendado instalar Vitis durante el proceso de instalación de ser necesario trabajar con MicroBlaze.

 

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

4. Para la instalación de Vivado 2020.2 se recomienda utilizar la versión de instalador ***"Windows self extracting web installer"*** para ahorrar tiempo y espacio en el disco duro, tiene un tamaño de 246.44  MB, como recomendación realizar la instalación utilizando una conexión por cable ethernet. Se debe seleccionar la versión **Vivado HL Design Edition** ya que esta es la que cuenta con más herramientas de síntesis, sin embargo es necesario tener acceso a una licencia. 

5. Para poder utilizar el soft processor **MicroBlaze** es necesario instalar **Vitis IDE**, esto se hace directamente al momento de la instalación de Vivado o después dando clic en `Help/Add Design Tools or Devices` e instalar Vitis.

6. Para poder acceder a los recursos y bibliotecas digitales es necesario conectarse mediante un proxy, para eso hay que seguir los siguientes pasos en Firefox:

   1. Dar clic en `Menú \ Opciones`y navegar hasta la parte inferior donde dice **Configuración de conexión** y dar clic en `Configurar...`
   2. Seleccionar `Configuración manual de proxy` e ingresar los siguientes datos:
      1. Proxy HTTP: `192.100.172.174`
      2. Puerto: `3128`
      3. Marcar `También usar este proxy para HTTPS` y Aceptar
      4. Reiniciar el navegador e ingresar las credenciales del servidor las cuales son las mismas que en el correo institucional.
   3. [Recursos electrónicos INAOE](https://www.inaoep.mx/biblioteca/e-recursos/) desde este link y una vez ingresadas las credenciales correctas se tiene acceso a todos lo recursos.

   


## Palabras clave

* TRNGs.
* Oscilador de anillo de efecto transitorio (TERO) .
* Efecto jitter - DPLL (Digital Phase-Locked Loop).
* Mapa caótico.
* Pseudo-random number generator.
* Stream cipher.
* Throughput.
* MAC (Message Authentication Code) or authenticated tag.
* Universal hash functions.
* Data integrity.
* Data authentication.
* Lyapunov exponent and fractal dimension
* Pseudo-dot product.
* Hash functions.



## Pruebas estandarizadas

* NIST suite 800-22a (National  Institute of Stanteds and Technology)
* TestU01suite 
  * Rabbit. (38 different statistical tests)
  * Alphabit. (17different statistical tests)
  * BlockAlphabit.



## Arquitecturas

* STM32F746ZG (development board Nucleo F746ZG, 216 MHz Cortex-M7F core, 1024 KB flash, and 336
  KB SRAM).
  
  

## Mapas Caóticos

* Sprott
* Henon
* Chevysehv 
* Sine ICMIC modulation
* Bernoulli shift map
* Tent
* Zigzag
* Borujeni





## Notas de artículos

1. **2021 - Luis Gerardo De La Fraga - Designing an authenticated Hash function with a 2D chaotic map.**

   **Keywords:** 2D chaotic map · Data integrity · Keyed hash · Stream cipher · Chaos-based cryptography

   > The justification to image encryption is that images have certain characteristics as dataredundancy, strong correlation among adjacent pixels,being less sensitive as compared to the text data

   > The security to encrypt an image depends on the randomsequences generated with a given chaotic entity

   >The simplest way of xoring the image bits with the gen-erated binary random sequence is required to encryptthe image. The requirement is that the binary sequence must be random. If data (not only an image) are xoring with a random sequence, the resulted sequence is also random. 

   >Sprott 2D map,  only sums and multiplications
   >$$
   >\begin{array}{ccl}
   >		x_{n+1} & = &  a_{1} + a_{2}x_{n} + a_{3}x_{n}^{2} + a_{4}x_{n}y_{n} + a_{5}y_{n} + a_{6}y_{n}^{2}\\
   >		y_{n+1} & = &  a_{7} + a_{8}x_{n} + a_{9}x_{n}^{2} + a_{10}x_{n}y_{n} + a_{11}y_{n} + a_{12}y_{n}^{2}
   >		\end{array}
   >$$
   >
   
   >A sequence of pseudo-random bits can be generated in the following form. Given the initial values $x_{0}, y_{0}$ the following numbers $x_{n+1}$ and $y_{n+1}$ are calculated and at each $n+1$ iteration 16 random bits of the sequence $s$ are generated as
   >$$
   >s_{n+1} = \{ x_{n+1} \text{ mod } 256, \quad y_{n+1} \text{ mod } 256\}
   >$$
   >

   >The development board NucleoF746ZG was used. It has STM32F746ZGT6 MCU with up to 216 MHz Cortex-M7F core, 1024 KB flash, and 336 KB SRAM. This MCU is 32 bits; thus, the multiplication of two 64-bit numbers was coded using 32-bit multiplications. The measured throughput was of 12.84 Kbits/s at the MCU working frequency of 16 MHz, or it could be 173.35 Kbits/s working at the maximum clock frequency of 216 MHz.

   >Function called StreamCipher, which receive as input a message of size $n$ bits; this function internally generates $⌈n/16⌉$ random words and apply xor operation between the message bits and the gener- ated random words.
   
   > A message authentication code (MAC) is generated by applying a hash function over the input message (line 2, in Algorithm 2), using a key K and a random sequence provided by a 2D map.
   
   > Our implementation of the hash function is based on the pseudo-dot product (PDP).
   
   
   
2. **2017 - Luis Gerardo De La Fraga - Hardware implementation of pseudo-random number
   generators based on chaotic maps**
   
   **Keywords:** 2D chaotic map · Data integrity · Keyed hash · Stream cipher · Chaos-based cryptography
   
   > The usefulness of bifurcation diagrams to implement a pseudo-random number generator (PRNG) based on chaotic maps. We provide details on the selection of the best parameter values to obtain high entropy and positive Lyapunov exponent from the bifurcation diagram of four chaotic maps namely: Bernoulli shift map, tent, zigzag, and Borujeni maps.
   
   > Nota
   
   > Nota
   
   > Nota
   
   > Nota
   
   > Nota
   
   > Nota
   
   > Nota
   
   > Nota
   
   > Nota
   
   > Nota
   
   
   
   

## [MicroBlaze](https://www.xilinx.com/products/design-tools/microblaze.html) Soft Processor FPGA Xilinx 

The MicroBlaze CPU is a family of drop-in, modifiable preset 32-bit/64-bit RISC microprocessor configurations. The MicroBlaze processor meets the requirements of many diverse applications including Industrial, Medical, Automotive, Consumer, and Communications markets.

To help you quickly deploy your application, the MicroBlaze processor includes three preset configurations analogous to familiar processor classes.

- **Microcontroller:** Suitable for running baremetal code
- **Real-Time Processor:** Deterministic real-time processing on an RTOS
- **Application Processor:** Embedded Linux capable

Experienced FPGA designers can use the Vivado® HL Edition design tools to target the MicroBlaze processor to any supported Xilinx device at no extra cost. Starting from one of these configurable presets, further customization is possible from a variety of specific processor options and a catalog of driver-enabled drag n’ drop peripherals such as PWMs, UARTs, DMAs, serial interfaces, to satisfy the specific needs of the application. It is also available as part of legacy IDS embedded edition for older FPGA device families like Spartan®-6.

**Key Capabilities**

- 32-bit instruction set and general purpose registers
- 32-bit address bus, extensible to 64 bits
- Lockstep & TMR Capable
- Optional floating point unit
- Sleep, Hibernate, and Suspend Mode/Instructions



### Implementación de una transmisión UART con el soft processor MicroBlaze en la tarjeta de desarrollo Basys 3

1. Crear un nuevo proyecto en Vivado 2020.2 seleccionando el número de parte de la tarjeta que se tenga, en mi caso es el chip `xc7a35tcpg236-1` el cual corresponde a la Basys 3.

2. Dar clic en Design Sources y después en el menú de **IP Integrator** dar clic en **Create Block Design** y nombrarlo UART_Demo y dejar lo demás por Default.

3. En la ventana Diagram, dar clic en **Add IP** (signo de más) y buscar **MicroBlaze MCS** y dar doble clic.

4. Dar doble clic sobre MicroBlaze MCS y configurar de la siguiente manera y dar clic OK:

   **MCS**

   | Configuración                  | Valor   |
   | ------------------------------ | ------- |
   | Memory Size                    | 8KB     |
   | Select MicroBlaze Optimization | AREA    |
   | Enable IO Bus                  | Uncheck |
   | Enable MicroBlaze Trace Bus    | Uncheck |
   | Enable Debug Support           | NONE    |
   
   **UART**
   
   | Configuración                | Valor   |
   | ---------------------------- | ------- |
   | Enable Receiver              | Uncheck |
   | Enable Transmiter            | Check   |
   | Define Baud Rate             | 115200  |
   | Number of Data Bits          | 8       |
   | Use Parity                   | Uncheck |
   | Implement Transmit Interrupt | Uncheck |
   
   **FIT**
   
   | Configuración | Valor   |
   | ------------- | ------- |
   | Use Timer     | Uncheck |
   
   **PIT**
   
   | Configuración | Valor   |
   | ------------- | ------- |
   | Use Timer     | Uncheck |
   
   **GPO and GPI**
   
   | Configuración      | Valor       |
   | ------------------ | ----------- |
   | Use GPO or Use GPI | All Uncheck |
   
   **Interrupts**
   
   | Configuración           | Valor   |
   | ----------------------- | ------- |
   | Use External Interrupts | Uncheck |
   
5. Dar sobre cualquier parte blanco del diagrama y seleccionar **Create Port**, este paso se repetirá 3 veces  con las siguientes configuraciones:

   | Port Name:  | Direction: | Type  | Extras                |
   | ----------- | ---------- | ----- | --------------------- |
   | `Input_Clk` | Input      | Clock | Frequency (MHz) 100   |
   | `Reset_Top` | Input      | Reset | Polarity (Active Low) |
   | `UART_Tx`   | Output     | Other | NA                    |

6. Una vez colocados los puertos anteriores conectarlos como corresponde, después dar clic derecho en el `.bd`que se encuentra en la pestaña Design Sources y seleccionar en **Create HDL Wrapper**. Esto generará un código VHDL que corresponde al MicroBlaze con las especiaciones dadas.

7. Realizar la asignación de puertos en hardware dado clic derecho  en **Constraints** y después **Add Sources**, seleccionar **Add or create constraints**, después **Create File**, el File type debe ser **XDC** y lo nombramos `pines`. Una vez creado lo abrimos y creamos la asignación de la siguiente manera.

   ```
   # Reloj
   set_property -dict { PACKAGE_PIN W5 IOSTANDARD LVCMOS33 } [get_ports { Input_Clk }];
   create_clock -add -name sys_clk_pin -period 10.00 -waveform {0 5} [get_ports { Input_Clk }]; 
   
   #Reset
   set_property -dict { PACKAGE_PIN R2 IOSTANDARD LVCMOS33 } [get_ports { Reset_Top }];
   
   # USB-RS232 Interface
   set_property -dict { PACKAGE_PIN A18 IOSTANDARD LVCMOS33 } [get_ports { UART_Tx }];
   ```

8. Dar clic en **Run Synthesis** y después en **Run Implementation**, si todo es correcto enseguida damos clic en **FIle/Export Hardware**, seleccionamos **Pre-synthesis** y nos aseguramos que la carpeta contenedora sea la del mismo proyecto.

9. Ahora para programar el soft processor MicroBlaze utilizaremos **Vitis IDE** el cual abrimos haciendo clic en **Tools/Launch Vitis IDE**.

10. Creamos un nuevo proyecto en **File/New/Platform Project** y lo nombramos UART_Demo_Vitis, después seleccionamos nuestro archivo `.xsa` y seleccionamos **stadalone** para el Operating system y **microblaze_mcs_0_microblaze_I** para el Processor.

11. Ahora vamos a crear la aplicación dando clic en **File/New/Application Project**, seleccionamos la plataforma correcta y despúes nombramos al proyecto UART_Demo_App y damos clic en Next hasta llegar a los Templates en el que seleccionamos Hello World y después Finish.

12. Abrimos `helloworld.c` y lo modificamos de la siguiente manera:

    ```c
    #include <stdio.h>
    #include "platform.h"
    #include "xil_printf.h"
    
    int main()
    {
    	int i, j;
    	for(i = 0; i < 10; i++){
    		print("Hello World\n\r");
    		for(j = 0; j < 5000000; j++ ){
    			// empty create delay
    		}
    	}
        init_platform();
        print("Code Complete!\n\r");
        cleanup_platform();
        return 0;
    }
    ```

    Con el siguiente código mandamos por comunicación serial la frase `Hello World\n\r` 10 veces y al final un aviso que el código ya terminó.

13. Compilamos el proyecto dando clic derecho sobre el proyecto en la ventana Explorer y seleccionando **Build Project**. 

    



> **Nota:** La diferencia entre MicroBlaze y MicroBlaze MCS es que el segundo utiliza menos recursos y es más sencillo de configurar por esta razón.

## Basys3

* Number part: xc7a35tcpg236-1



