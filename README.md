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
   3. [Recursos electrónicos INAOE](https://www.inaoep.mx/biblioteca/recursos-electronicos) desde este link y una vez ingresadas las credenciales correctas se tiene acceso a todos lo recursos.

   


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
* Entropy. 
* TISEAN.
* Context-tree weighting (CTW) algorithm.
* Bit counting redundancy reduction technique.
* Programmable delay lines (PDLs) .
* MD5 algorithm.
* Phase-locked loops (PLLs).
* Digital clock management (DCM).
* Ring oscillators (ROs).
* Self-timed rings (STRs).
* Muller C-element



## Pruebas estandarizadas

* NIST suite 800-22a (National  Institute of Stanteds and Technology)
* TestU01suite 
  * Rabbit. (38 different statistical tests)
  * Alphabit. (17different statistical tests)
  * BlockAlphabit.
* Diehard.



## Arquitecturas

* STM32F746ZG (development board Nucleo F746ZG, 216 MHz Cortex-M7F core, 1024 KB flash, and 336 KB SRAM).
* FPGA Spartan 3E (xc3s500e-4fg320).
* FPGA Cyclone IV EP4CGX150DF31C7.
* FPGA XC7VX485T-2-FFG1761 chip of the Virtex-7 VC707.
* Xilinx Spartan-3A FPGAs (XC3S400A-4FTG256).

## Mapas Caóticos

* Sprott
* Henon
* Chevysehv 
* Sine ICMIC modulation
* Bernoulli shift map
* Tent
* Zigzag
* Borujeni



## Throughput

* 12.84 Kbits/s at 16 MHz or 173.35 Kbits/s at 216 MHz
* 7.38 Mb/s 
* 100 Mbps

## Bibliografía

1. **2021 - Luis Gerardo De La Fraga - Designing an authenticated Hash function with a 2D chaotic map.**
2. **2017 - Luis Gerardo De La Fraga - Hardware implementation of pseudo-random number generators based on chaotic maps.** 
3. **2021 - Sundarapandian Vaidyanathan - A 5-D Multi-Stable Hyperchaotic Two-Disk Dynamo System With No Equilibrium Point: Circuit Design, FPGA Realization and Applications to TRNGs and Image Encryption.** 
4. **2020 - N. Nalla Anandakumar - FPGA-Based True Random Number Generation Using Programmable Delays in Oscillator-Rings.** 
5. **1999 - Benjamin Jun and Paul Kocher - The Intel Random Number Generator.** 
6. **2021 - Xinyu Wang - High-Throughput Portable True Random Number Generator Based on Jitter-Latch Structure.** 
7. **2021 - Adriaan Peetermans - Design and Analysis of Configurable Ring Oscillators for True Random Number Generation Based on Coherent Sampling.** 
8. **2016 - Oto Petura - A Survey of AIS-20/31 Compliant TRNG Cores Suitable for FPGA Devices.** 
9. **1993 - J.C. Sprott - Automatic generation of strange attractors.** 
10. **2015 - Patrick Haddad - A Physical Approach for Stochastic Modeling of TERO-Based TRNG.** 
11. **2010 - Mathieu Baudet - On the Security of Oscillator-Based Random Number Generators.** 
12.  **2010 - Michal Varchola - New High Entropy Element for FPGA Based True Random Number Generators.** 



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
  #create_clock -add -name sys_clk_pin -period 10.00 -waveform {0 5} [get_ports {  CLK100MHZ }];
   
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
  
  # Buttons
  #set_property -dict { PACKAGE_PIN U18   IOSTANDARD LVCMOS33 } [get_ports { btnC }];
  #set_property -dict { PACKAGE_PIN T18   IOSTANDARD LVCMOS33 } [get_ports { btnU }];
  #set_property -dict { PACKAGE_PIN W19   IOSTANDARD LVCMOS33 } [get_ports { btnL }];
  #set_property -dict { PACKAGE_PIN T17   IOSTANDARD LVCMOS33 } [get_ports { btnR }];
  #set_property -dict { PACKAGE_PIN U17   IOSTANDARD LVCMOS33 } [get_ports { btnD }];
  
  # Pmod Header JA
  #set_property -dict { PACKAGE_PIN J1   IOSTANDARD LVCMOS33 } [get_ports { JA[0] }];	#Sch name = JA1
  #set_property -dict { PACKAGE_PIN L2   IOSTANDARD LVCMOS33 } [get_ports { JA[1] }];	#Sch name = JA2
  #set_property -dict { PACKAGE_PIN J2   IOSTANDARD LVCMOS33 } [get_ports { JA[2] }];	#Sch name = JA3
  #set_property -dict { PACKAGE_PIN G2   IOSTANDARD LVCMOS33 } [get_ports { JA[3] }];	#Sch name = JA4
  #set_property -dict { PACKAGE_PIN H1   IOSTANDARD LVCMOS33 } [get_ports { JA[4] }];	#Sch name = JA7
  #set_property -dict { PACKAGE_PIN K2   IOSTANDARD LVCMOS33 } [get_ports { JA[5] }];	#Sch name = JA8
  #set_property -dict { PACKAGE_PIN H2   IOSTANDARD LVCMOS33 } [get_ports { JA[6] }];	#Sch name = JA9
  #set_property -dict { PACKAGE_PIN G3   IOSTANDARD LVCMOS33 } [get_ports { JA[7] }];	#Sch name = JA10
  
  # Pmod Header JB
  #set_property -dict { PACKAGE_PIN A14   IOSTANDARD LVCMOS33 } [get_ports { JB[0] }]; #Sch name = JB1
  #set_property -dict { PACKAGE_PIN A16   IOSTANDARD LVCMOS33 } [get_ports { JB[1] }]; #Sch name = JB2
  #set_property -dict { PACKAGE_PIN B15   IOSTANDARD LVCMOS33 } [get_ports { JB[2] }]; #Sch name = JB3
  #set_property -dict { PACKAGE_PIN B16   IOSTANDARD LVCMOS33 } [get_ports { JB[3] }]; #Sch name = JB4
  #set_property -dict { PACKAGE_PIN A15   IOSTANDARD LVCMOS33 } [get_ports { JB[4] }]; #Sch name = JB7
  #set_property -dict { PACKAGE_PIN A17   IOSTANDARD LVCMOS33 } [get_ports { JB[5] }]; #Sch name = JB8
  #set_property -dict { PACKAGE_PIN C15   IOSTANDARD LVCMOS33 } [get_ports { JB[6] }]; #Sch name = JB9
  #set_property -dict { PACKAGE_PIN C16   IOSTANDARD LVCMOS33 } [get_ports { JB[7] }]; #Sch name = JB10 
  
  # Pmod Header JC
  #set_property -dict { PACKAGE_PIN K17   IOSTANDARD LVCMOS33 } [get_ports { JC[0] }]; #Sch name = JC1
  #set_property -dict { PACKAGE_PIN M18   IOSTANDARD LVCMOS33 } [get_ports { JC[1] }]; #Sch name = JC2
  #set_property -dict { PACKAGE_PIN N17   IOSTANDARD LVCMOS33 } [get_ports { JC[2] }]; #Sch name = JC3
  #set_property -dict { PACKAGE_PIN P18   IOSTANDARD LVCMOS33 } [get_ports { JC[3] }]; #Sch name = JC4
  #set_property -dict { PACKAGE_PIN L17   IOSTANDARD LVCMOS33 } [get_ports { JC[4] }]; #Sch name = JC7
  #set_property -dict { PACKAGE_PIN M19   IOSTANDARD LVCMOS33 } [get_ports { JC[5] }]; #Sch name = JC8
  #set_property -dict { PACKAGE_PIN P17   IOSTANDARD LVCMOS33 } [get_ports { JC[6] }]; #Sch name = JC9
  #set_property -dict { PACKAGE_PIN R18   IOSTANDARD LVCMOS33 } [get_ports { JC[7] }]; #Sch name = JC10
  
  # Pmod Header JXADC
  #set_property -dict { PACKAGE_PIN J3   IOSTANDARD LVCMOS33 } [get_ports { JXADC[0] }];	#Sch name = XA1_P
  #set_property -dict { PACKAGE_PIN L3   IOSTANDARD LVCMOS33 } [get_ports { JXADC[1] }];	#Sch name = XA2_P
  #set_property -dict { PACKAGE_PIN M2   IOSTANDARD LVCMOS33 } [get_ports { JXADC[2] }];	#Sch name = XA3_P
  #set_property -dict { PACKAGE_PIN N2   IOSTANDARD LVCMOS33 } [get_ports { JXADC[3] }];	#Sch name = XA4_P
  #set_property -dict { PACKAGE_PIN K3   IOSTANDARD LVCMOS33 } [get_ports { JXADC[4] }];	#Sch name = XA1_N
  #set_property -dict { PACKAGE_PIN M3   IOSTANDARD LVCMOS33 } [get_ports { JXADC[5] }];	#Sch name = XA2_N
  #set_property -dict { PACKAGE_PIN M1   IOSTANDARD LVCMOS33 } [get_ports { JXADC[6] }];	#Sch name = XA3_N
  #set_property -dict { PACKAGE_PIN N1   IOSTANDARD LVCMOS33 } [get_ports { JXADC[7] }];	#Sch name = XA4_N
  
  # VGA Connector
  #set_property -dict { PACKAGE_PIN G19   IOSTANDARD LVCMOS33 } [get_ports { vgaRed[0] }];
  #set_property -dict { PACKAGE_PIN H19   IOSTANDARD LVCMOS33 } [get_ports { vgaRed[1] }];
  #set_property -dict { PACKAGE_PIN J19   IOSTANDARD LVCMOS33 } [get_ports { vgaRed[2] }];
  #set_property -dict { PACKAGE_PIN N19   IOSTANDARD LVCMOS33 } [get_ports { vgaRed[3] }];
  #set_property -dict { PACKAGE_PIN N18   IOSTANDARD LVCMOS33 } [get_ports { vgaBlue[0] }];
  #set_property -dict { PACKAGE_PIN L18   IOSTANDARD LVCMOS33 } [get_ports { vgaBlue[1] }];
  #set_property -dict { PACKAGE_PIN K18   IOSTANDARD LVCMOS33 } [get_ports { vgaBlue[2] }];
  #set_property -dict { PACKAGE_PIN J18   IOSTANDARD LVCMOS33 } [get_ports { vgaBlue[3] }];
  #set_property -dict { PACKAGE_PIN J17   IOSTANDARD LVCMOS33 } [get_ports { vgaGreen[0] }];
  #set_property -dict { PACKAGE_PIN H17   IOSTANDARD LVCMOS33 } [get_ports { vgaGreen[1] }];
  #set_property -dict { PACKAGE_PIN G17   IOSTANDARD LVCMOS33 } [get_ports { vgaGreen[2] }];
  #set_property -dict { PACKAGE_PIN D17   IOSTANDARD LVCMOS33 } [get_ports { vgaGreen[3] }];
  #set_property -dict { PACKAGE_PIN P19   IOSTANDARD LVCMOS33 } [get_ports { Hsync }];
  #set_property -dict { PACKAGE_PIN R19   IOSTANDARD LVCMOS33 } [get_ports { Vsync }];
  
  # USB-RS232 Interface
  #set_property -dict { PACKAGE_PIN B18   IOSTANDARD LVCMOS33 } [get_ports { RsRx }]:
  #set_property -dict { PACKAGE_PIN A18   IOSTANDARD LVCMOS33 } [get_ports { RsTx }]:
  
  # USB HID (PS/2)
  #set_property -dict { PACKAGE_PIN C17   IOSTANDARD LVCMOS33 } [get_ports { PS2Clk }];
  #set_property PULLUP true [get_ports { PS2Clk }];
  #set_property -dict { PACKAGE_PIN B17   IOSTANDARD LVCMOS33 } [get_ports { PS2Data }];
  #set_property PULLUP true [get_ports { PS2Data }];
  
  # Quad SPI Flash
  # Note that CCLK_0 cannot be placed in 7 series devices. You can access it using the
  # STARTUPE2 primitive.
  #set_property -dict { PACKAGE_PIN D18   IOSTANDARD LVCMOS33 } [get_ports { QspiDB[0] }];
  #set_property -dict { PACKAGE_PIN D19   IOSTANDARD LVCMOS33 } [get_ports { QspiDB[1] }];
  #set_property -dict { PACKAGE_PIN G18   IOSTANDARD LVCMOS33 } [get_ports { QspiDB[2] }];
  #set_property -dict { PACKAGE_PIN F18   IOSTANDARD LVCMOS33 } [get_ports { QspiDB[3] }];
  #set_property -dict { PACKAGE_PIN K19   IOSTANDARD LVCMOS33 } [get_ports { QspiCSn }];		
  
  # Configuration options, can be used for all designs
  #set_property CONFIG_VOLTAGE 3.3 [current_design]
  #set_property CFGBVS VCCO [current_design]
  ```




## Artículos por leer sacados de las referencias de los artículos ya leídos

* Un articulo





