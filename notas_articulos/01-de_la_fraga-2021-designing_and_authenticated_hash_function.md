---
tags: [articulo]
name: "Designing an authenticated Hash function with a 2D chaotic map"
alias: 01_fraga_2021
authors: [Luis Gerardo De la Fraga, Cuahtemoc Mancillas-Lopez, Esteban Tlelo-Cuautle]
year: 2021
bibtex: Fraga2021
keywords: [chaotic map, data integrity,  keyed hash, stream cipher, chaos-based cryptography, prng, nist, testu01, encrypt images, hash function]
doi: https://doi.org/10.1007/s11071-021-06491-3
references:
---

## Resumen e introducción 
#throughput
El generador de secuencias aleatorias se probó en un microcontrolador de altas prestaciones STM32F746ZG obteniendo un throughput (rendimiento/ tasa de bits) de 173,35Kbit/s.

#image_encryption #chaotic_maps
El termino "cifrado de imágenes" se utiliza para indicar la aplicación de entidades caóticas, principalmente mapas, para proteger imágenes cifrándolas. La justificación de la encriptación de imágenes es que éstas presentan ciertas características, como redundancia de datos, fuerte correlación entre píxeles adyacentes, menor sensibilidad en comparación con los datos de texto.

#chaotic
Demostramos que la seguridad para cifrar y generar un código de autenticación de mensajes (MAC), o una etiqueta de autenticación, para una imagen no depende de ninguna característica de la imagen, ni de la distribución especial de los datos de la imagen. La seguridad para cifrar una imagen depende de las secuencias aleatorias generadas con una entidad caótica determinada.

Afirmamos que la única forma de detectar si una imagen (o cualquier información) ha sido modificada es creando una función de integridad de la imagen. Esta función calcula una etiqueta de autenticación para la imagen, la cifra y la almacena junto a la imagen de entrada. Cada vez que es necesario comprobar si la información almacenada no está en peligro, la etiqueta de autenticación debe calcularse de nuevo a partir de los datos y compararse con la almacenada.

#chaotic_maps #examples
Los mapas caóticos se han utilizado para crear generadores de números pseudoaleatorios (PRNG). Los mapas caóticos son una fuente de entropía para los PRNG.

## Aportaciones
- El uso del mapa caótico 2D, que sólo utiliza sumas y multiplicaciones de números enteros, para generar una secuencia de números binarios aleatorios. Este mapa no se ha utilizado antes para generar números aleatorios.
- Cifrar datos de imágenes con la operación **xor** entre los bits de la imagen y la secuencia aleatoria generada. De hecho, este procedimiento puede utilizarse para cifrar cualquier dato digital, no sólo imágenes.
- Utilizar un mapa caótico como base para generar una función hash con clave, en la que la clave es una larga secuencia de números aleatorios, para la integridad de la imagen en su transmisión y cifrado. El hash con clave puede detectar cualquier cambio aplicado a la imagen original o cifrada. Además, hasta donde sabemos, es la primera vez que se utiliza un mapa caótico como núcleo para implementar una función hash con clave.

## Solución de problemas
- No utilizamos aritmética de coma flotante, lo que evita problemas de cuantización que evita problemas de cuantización.
- Los píxeles de la imagen no se permutan, lo que podría ser utilizado por ataques de seguridad de texto plano.
- Se utilizan 64 bits en los cálculos, lo que lleva tanto a evitar periodos bajos y degradación en el mapa utilizado, como a utilizar claves más amplias.


| Acrónimo | Significado  |
| ------- | --------------------------- |
| MAC     | Message Authentication Code | 


## Referencias útiles

| Número | En mi bibliografía | Etiqueta                   | Nombre                                                                                                                                          | Enlace                                                                                                 |
| ------ | ------------------ | -------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------ |
| 7      | 2                  | #chaotic_maps              | Hardware implementation of pseudorandom number generators based on chaotic maps                                                                 | [[02-de_la_fraga-2017-hardware_implementaion_of_pseudo-random_number_generator\|02_fraga_2017]]        |
| 17     | 26                 | #chaotic_maps              | A novel image encryption scheme based on improved random number generator and its implementation                                                | [[26-li-2018-a_novel_image_encryption\|26_li_2018]]                                                    |
| 26     | 25                 | #chaotic_logistic_map      | Image encryption using chaotic logistic map                                                                                                     | [[25-pareek-2006-image_encryption_using_chaotic_logistic_map\|25_pareek_2006]]                         |
| 31     | 27                 | #chaotic_system            | A new 4-D chaotic hyperjerk system, its synchronization, circuit design and applications in RNG, image encryption and chaos-based steganography | [[27-vaidyanathan-2018-a_new_4d_chaotic_system_applications_in_rgn\|27_vaidyanathan_2018]]             |
| 11     | 28                 | #chaotic                   | Randomness improvement of chaotic maps for image encryption in a wireless communication scheme using PIC-microcontroller via Zigbee channels    | [[28_garcia_2020-randomness_improvement_of_chaotic_maps_image_pic\|28_garcia_2020]]                    |
| 15     | 29                 | #chaotic_maps              | A modified image encryption scheme based on 2D chaotic map                                                                                      | [[29-kadir-2010-a_modified_image_encryption_scheme_based_on_2d_chaotic_map\|29_kadir_2010]]            |
| 21     | 24                 | #chaotic_maps              | Colour image encryption based on advanced encryption standard algorithm with two-dimensional chaotic map                                        | [[24-Li-2013-colour_image_encryption_based_on_advanced_encryption_standard_algorithm\|24_obaida_2013]] |
| 23     | 30                 | #chaotic_maps              | A fast image encryption algorithm based on chaotic map                                                                                          | [[30-Liu-2016-a_fast_image_encryption_algorithm_based_on_chaotic_map\|30_liu_2016]]                    |
| 32     | 31                 | #chaotic_maps              | A fast image encryption scheme based on chaotic standard map                                                                                    | [[31-wong-2008-a_fast_image_encryption_scheme_based_on_chaotic_standard_map\|31_wong_2008]]            |
| 20     | 33                 | #image_encryption_problems | When an attacker meets a cipher-image in 2018: A year in review                                                                                 | [[33-li-2019-when_attacker_meets_a_cipher_image_in_2018\|33_li_2019]]                                  |
| 18     | 32                 | #image_encryption_problems | Cryptanalyzing an Image Encryption Algorithm Based on Autoblocking and Electrocardiography                                                      | [[32-li-2018-cryptanalysing_an_image_encryption_algorithm_based_on_electrocardiography\|32_li_2018]]   | 

