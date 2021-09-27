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

* TRNGs (True Random Number Generators).
* RNG (Random Number Generators).
* Randomness.
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
   >
   >![\begin{array}{ccl}
   >		x_{n+1} & = &  a_{1} + a_{2}x_{n} + a_{3}x_{n}^{2} + a_{4}x_{n}y_{n} + a_{5}y_{n} + a_{6}y_{n}^{2}\\
   >		y_{n+1} & = &  a_{7} + a_{8}x_{n} + a_{9}x_{n}^{2} + a_{10}x_{n}y_{n} + a_{11}y_{n} + a_{12}y_{n}^{2}
   >		\end{array}
   >](https://render.githubusercontent.com/render/math?math=%5Cdisplaystyle+%5Cbegin%7Barray%7D%7Bccl%7D%0A%09%09x_%7Bn%2B1%7D+%26+%3D+%26++a_%7B1%7D+%2B+a_%7B2%7Dx_%7Bn%7D+%2B+a_%7B3%7Dx_%7Bn%7D%5E%7B2%7D+%2B+a_%7B4%7Dx_%7Bn%7Dy_%7Bn%7D+%2B+a_%7B5%7Dy_%7Bn%7D+%2B+a_%7B6%7Dy_%7Bn%7D%5E%7B2%7D%5C%5C%0A%09%09y_%7Bn%2B1%7D+%26+%3D+%26++a_%7B7%7D+%2B+a_%7B8%7Dx_%7Bn%7D+%2B+a_%7B9%7Dx_%7Bn%7D%5E%7B2%7D+%2B+a_%7B10%7Dx_%7Bn%7Dy_%7Bn%7D+%2B+a_%7B11%7Dy_%7Bn%7D+%2B+a_%7B12%7Dy_%7Bn%7D%5E%7B2%7D%0A%09%09%5Cend%7Barray%7D%0A)
   
   >A sequence of pseudo-random bits can be generated in the following form. Given the initial values ![x_{0}, y_{0}](https://render.githubusercontent.com/render/math?math=%5Ctextstyle+x_%7B0%7D%2C+y_%7B0%7D) the following numbers ![x_{n+1}](https://render.githubusercontent.com/render/math?math=%5Ctextstyle+x_%7Bn%2B1%7D) and ![y_{n+1}](https://render.githubusercontent.com/render/math?math=%5Ctextstyle+y_%7Bn%2B1%7D) are calculated and at each ![n+1](https://render.githubusercontent.com/render/math?math=%5Ctextstyle+n%2B1) iteration 16 random bits of the sequence $s$ are generated as
   >
   >![s_{n+1} = \{ x_{n+1} \text{ mod } 256, \quad y_{n+1} \text{ mod } 256\}
   >](https://render.githubusercontent.com/render/math?math=%5Cdisplaystyle+s_%7Bn%2B1%7D+%3D+%5C%7B+x_%7Bn%2B1%7D+%5Ctext%7B+mod+%7D+256%2C+%5Cquad+y_%7Bn%2B1%7D+%5Ctext%7B+mod+%7D+256%5C%7D%0A)
   
   >The development board NucleoF746ZG was used. It has STM32F746ZGT6 MCU with up to 216 MHz Cortex-M7F core, 1024 KB flash, and 336 KB SRAM. This MCU is 32 bits; thus, the multiplication of two 64-bit numbers was coded using 32-bit multiplications. The measured throughput was of 12.84 Kbits/s at the MCU working frequency of 16 MHz, or it could be 173.35 Kbits/s working at the maximum clock frequency of 216 MHz.

   >Function called StreamCipher, which receive as input a message of size ![n](https://render.githubusercontent.com/render/math?math=%5Ctextstyle+n) bits; this function internally generates ⌈![n/16](https://render.githubusercontent.com/render/math?math=%5Ctextstyle+n%2F16)⌉ random words and apply xor operation between the message bits and the gener- ated random words.

   > A message authentication code (MAC) is generated by applying a hash function over the input message (line 2, in Algorithm 2), using a key K and a random sequence provided by a 2D map.
   
   > Our implementation of the hash function is based on the pseudo-dot product (PDP).
   
   
   
   
   
2. **2017 - Luis Gerardo De La Fraga - Hardware implementation of pseudo-random number
   generators based on chaotic maps**

   **Keywords:** Chaotic map 

   > The usefulness of bifurcation diagrams to implement a pseudo-random number generator (PRNG) based on chaotic maps. We provide details on the selection of the best parameter values to obtain high entropy and positive Lyapunov exponent from the bifurcation diagram of four chaotic maps namely: Bernoulli shift map, tent, zigzag, and Borujeni maps.

   > The binary sequences obtained from these maps are analyzed to implement a PRNG both in software and in hardware. The software implementation is realized using 32 and 64bits microprocessor architectures, and with floating point and fixed point computer arithmetic. The hardware implementation is done by using a field-programmable gate array (FPGA) architecture.

   > We show that those chaotic maps are suitable to implement a PRNG but according to the hardware resources, the one based on the Bernoulli shift map isbetter. In addition, another advantage is that the required initial value for the sequences can be within the whole interval [−1,1], including its bounds.

   > In 1999, Intel introduced a silicon-based random number generator (RNG).  Intel suggested that to define the concept of a RNG, it is first necessary to understand the idea of randomness, which is typically associated with unpredictability, chance and luck.

   > Knuth D.E in The Art of Computer Programming Volume 2 defines random numbers as a sequence of independent numbers with a specified distribution and a specified probability of falling in any given range of values. As a result, the ideal RNG will provide a stream of uniformly distributed, nondeterministic, and independent bits over an infinite data set.

   > As nowadays known, because the mathematical evaluation of randomness is difficult, it is only possible to use statistical analyses on sample data sets to detect characteristics that point to non-randomness, and one way is by performing tests from the NIST suite.

   > Applications: Entertainment like lotteries, video games, music, graphics, complex scientific, financial models, artificial intelligence,  to test programs and algorithms to detect bugs, equation-Solving, cryptography, digital signatures, protected communication protocols, and so on.

   > A RNG is a physical device or software from which a sequence of random binary numbers is obtained. If this generator is a nondeterministic system; then, it is called a truly RNG (TRNG); otherwise, the system is called a pseudo-RNG (PRNG).

   > Because PRNGs employ a mathematical algorithm for number generation, all PRNGs possess the following properties: A seed value is required to initialize the equation, and the sequence will cycle after a particular period. Therefore, application developers must provide unguessable seed value and an algorithm with a period that is sufficiently long, and also they must verify that the PRNG output contains no correlation or bias.

   > It is known that map-based TRNGs have many challenges associated with non-ideal effects, which in the majority of cases are inherent to the integrated circuit (IC) fabrication technology process. 

   > Nota

   > Nota

   > Nota
   
   > Nota
   
   > Nota
   
   > Nota
   
   > Nota
   
   > Nota
   
   
   
   
   
3. 

## Bibliografía

1. **2021 - Luis Gerardo De La Fraga - Designing an authenticated Hash function with a 2D chaotic map.**
2. **2017 - Luis Gerardo De La Fraga - Hardware implementation of pseudo-random number
   generators based on chaotic maps.**
3. 

   

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

* Constraints file:

  ```
  ## This file is a general .xdc for the Basys3 rev B board
  ## To use it in a project:
  ## - uncomment the lines corresponding to used pins
  ## - rename the used ports (in each line, after get_ports) according to the top level signal names in the project
  
  # Clock signal
  #set_property -dict { PACKAGE_PIN R2 IOSTANDARD LVCMOS33 } [get_ports { CLK100MHZ }]; 
  #create_clock -add -name sys_clk_pin -period 10.00 -waveform {0 5} [get_ports CLK100MHZ]
   
  # Switches
  #set_property -dict { PACKAGE_PIN V17   IOSTANDARD LVCMOS33 } [get_ports { sw[0] }];
  #set_property -dict { PACKAGE_PIN V16   IOSTANDARD LVCMOS33 } [get_ports { sw[1] }];
  #set_property -dict { PACKAGE_PIN W16   IOSTANDARD LVCMOS33 } [get_ports { sw[2] }];
  #set_property -dict { PACKAGE_PIN W17   IOSTANDARD LVCMOS33 } [get_ports { sw[3] }];
  #set_property -dict { PACKAGE_PIN W15   IOSTANDARD LVCMOS33 } [get_ports { sw[4] }];
  #set_property -dict { PACKAGE_PIN V15   IOSTANDARD LVCMOS33 } [get_ports { sw[5] }];
  #set_property -dict { PACKAGE_PIN W14   IOSTANDARD LVCMOS33 } [get_ports { sw[6] }];
  #set_property -dict { PACKAGE_PIN W13   IOSTANDARD LVCMOS33 } [get_ports { sw[7] }];
  #set_property -dict { PACKAGE_PIN V2   IOSTANDARD LVCMOS33 } [get_ports { sw[8] }];
  #set_property -dict { PACKAGE_PIN T3   IOSTANDARD LVCMOS33 } [get_ports { sw[9] }];
  #set_property -dict { PACKAGE_PIN T2   IOSTANDARD LVCMOS33 } [get_ports { sw[10] }];
  #set_property -dict { PACKAGE_PIN R3   IOSTANDARD LVCMOS33 } [get_ports { sw[11] }];
  #set_property -dict { PACKAGE_PIN W2   IOSTANDARD LVCMOS33 } [get_ports { sw[12] }];
  #set_property -dict { PACKAGE_PIN U1   IOSTANDARD LVCMOS33 } [get_ports { sw[13] }];
  #set_property -dict { PACKAGE_PIN T1   IOSTANDARD LVCMOS33 } [get_ports { sw[14] }];
  #set_property -dict { PACKAGE_PIN R2   IOSTANDARD LVCMOS33 } [get_ports { sw[15] }];
   
  # LEDs
  #set_property -dict { PACKAGE_PIN U16   IOSTANDARD LVCMOS33 } [get_ports { LED[0] }];
  #set_property -dict { PACKAGE_PIN E19   IOSTANDARD LVCMOS33 } [get_ports { LED[1] }];
  #set_property -dict { PACKAGE_PIN U19   IOSTANDARD LVCMOS33 } [get_ports { LED[2] }];
  #set_property -dict { PACKAGE_PIN V19   IOSTANDARD LVCMOS33 } [get_ports { LED[3] }];
  #set_property -dict { PACKAGE_PIN W18   IOSTANDARD LVCMOS33 } [get_ports { LED[4] }];
  #set_property -dict { PACKAGE_PIN U15   IOSTANDARD LVCMOS33 } [get_ports { LED[5] }];
  #set_property -dict { PACKAGE_PIN U14   IOSTANDARD LVCMOS33 } [get_ports { LED[6] }];
  #set_property -dict { PACKAGE_PIN V14   IOSTANDARD LVCMOS33 } [get_ports { LED[7] }];
  #set_property -dict { PACKAGE_PIN V13   IOSTANDARD LVCMOS33 } [get_ports { LED[8] };]
  #set_property -dict { PACKAGE_PIN V3   IOSTANDARD LVCMOS33 } [get_ports { LED[9] }];
  #set_property -dict { PACKAGE_PIN W3   IOSTANDARD LVCMOS33 } [get_ports { LED[10] }];
  #set_property -dict { PACKAGE_PIN U3   IOSTANDARD LVCMOS33 } [get_ports { LED[11] }];
  #set_property -dict { PACKAGE_PIN P3   IOSTANDARD LVCMOS33 } [get_ports { LED[12] }];	
  #set_property -dict { PACKAGE_PIN N3   IOSTANDARD LVCMOS33 } [get_ports { LED[13] }];
  #set_property -dict { PACKAGE_PIN P1   IOSTANDARD LVCMOS33 } [get_ports { LED[14] }];
  #set_property -dict { PACKAGE_PIN L1   IOSTANDARD LVCMOS33 } [get_ports { LED[15] }];
  	
  #7 segment display
  #set_property -dict { PACKAGE_PIN W7   IOSTANDARD LVCMOS33 } [get_ports { seg[0] }];
  #set_property -dict { PACKAGE_PIN W6   IOSTANDARD LVCMOS33 } [get_ports { seg[1] }];	
  #set_property -dict { PACKAGE_PIN U8   IOSTANDARD LVCMOS33 } [get_ports { seg[2] }];				
  #set_property -dict { PACKAGE_PIN V8   IOSTANDARD LVCMOS33 } [get_ports { seg[3] }];
  #set_property -dict { PACKAGE_PIN U5   IOSTANDARD LVCMOS33 } [get_ports { seg[4] }];
  #set_property -dict { PACKAGE_PIN V5   IOSTANDARD LVCMOS33 } [get_ports { seg[5] }];
  #set_property -dict { PACKAGE_PIN U7   IOSTANDARD LVCMOS33 } [get_ports { seg[6] }];
  
  #set_property -dict { PACKAGE_PIN V7   IOSTANDARD LVCMOS33 } [get_ports { dp }];
  #set_property -dict { PACKAGE_PIN U2   IOSTANDARD LVCMOS33 } [get_ports { an[0] }];
  #set_property -dict { PACKAGE_PIN U4   IOSTANDARD LVCMOS33 } [get_ports { an[1] }];
  #set_property -dict { PACKAGE_PIN V4   IOSTANDARD LVCMOS33 } [get_ports { an[2] }];
  #set_property -dict { PACKAGE_PIN W4   IOSTANDARD LVCMOS33 } [get_ports { an[3] }];
  
  #Buttons
  #set_property -dict { PACKAGE_PIN U18   IOSTANDARD LVCMOS33 } [get_ports { btnC }];
  #set_property -dict { PACKAGE_PIN T18   IOSTANDARD LVCMOS33 } [get_ports { btnU }];
  #set_property -dict { PACKAGE_PIN W19   IOSTANDARD LVCMOS33 } [get_ports { btnL }];
  #set_property -dict { PACKAGE_PIN T17   IOSTANDARD LVCMOS33 } [get_ports { btnR }];
  #set_property -dict { PACKAGE_PIN U17   IOSTANDARD LVCMOS33 } [get_ports { btnD }];
  ```

  





## Respaldo de ecuaciones

$$
\begin{array}{ccl}
		x_{n+1} & = &  a_{1} + a_{2}x_{n} + a_{3}x_{n}^{2} + a_{4}x_{n}y_{n} + a_{5}y_{n} + a_{6}y_{n}^{2}\\
		y_{n+1} & = &  a_{7} + a_{8}x_{n} + a_{9}x_{n}^{2} + a_{10}x_{n}y_{n} + a_{11}y_{n} + a_{12}y_{n}^{2}
		\end{array}
$$

$$
s_{n+1} = \{ x_{n+1} \text{ mod } 256, \quad y_{n+1} \text{ mod } 256\}
$$





## Artículos por leer sacados de las referencias de los artículos ya leídos

* Jun, B., Kocher, P.: The Intel Random Number Generator. Cryptography Research Inc. white paper, San Francisco (1999)
* Knuth, D.E.: The Art of Computer Programming Volume 2, Seminumerical Algorithms, 3rd edn. Addison Wesley, Boston (1998)
* Rukhin, A., Soto, J., Nechvatal, J., Smid, M., Barker, E., Leigh, S., Levenson, M., Vangel, M., Banks, D., Heckert, A., Dray, J., Vo, S.: A statistical test suite for the validation of random number generators and pseudo ran- dom number generators for cryptographic applications, 27 April 2010. SP800-22rev1a.pdf file, last date checked: 18 Feb 2016. http://csrc.nist.gov/groups/ST/toolkit/rng/documentation_software.html
* Valtierra, J.L., Tlelo-Cuautle, E., Rodríguez-Vázquez, Á.: A switched-capacitor skew-tent map implementation for random number generation. Int. J. Circuit Theory Appl. 45(2),305–315 (2017)
* Nejati, H., Beirami, A., Ali, W.H.: Discrete-time chaotic-map truly random number generators: design, implementation nd variability analysis of the zigzag map. Analog Integr. Circuits Signal Process. 73(1), 363–374 (2012)
* Cicek, I., Pusane, A.E., Dundar, G.: A novel design method for discrete time chaos based true random number generators. Integr. VLSI J. 47(1), 38–47 (2014)
