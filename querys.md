## Todos los archivos
```dataview
TABLE 
```


## Filtro por año
```dataview
TABLE Without ID
	name as Nombre,
	bibtex as BibTeX,
	authors as Autores,
	year as Año,
	alias as Alias,
	keywords as Keywords
WHERE contains(year, 2017)
SORT year DESC
```



## Filtro por autor
```dataview
TABLE Without ID
	name as Nombre,
	bibtex as BibTeX,
	authors as Autores,
	year as Año,
	alias as Alias,
	keywords as Keywords
WHERE contains(authors, "Sundar")
SORT year DESC
```



## Filtro por keywords
```dataview
TABLE Without ID
	name as Nombre,
	bibtex as BibTeX,
	authors as Autores,
	year as Año,
	alias as Alias,
	keywords as Keywords
WHERE contains(keywords, "cipher")
SORT year DESC
```