# Export of TemporalIso samples as csv

Writes the interval samples of a TemporalIso-object to a .csv-File.

## Usage

``` r
# S4 method for class 'TemporalIso'
export(fit, file, interval = NULL, ...)
```

## Arguments

- fit:

  TemporalIso: An instance of class TemporalIso, generated from
  [`estimateIntervals`](https://pandora-isomemo.github.io/OsteoBioR/reference/estimateIntervals.md)

- file:

  character: a character string specifying the path to a .csv-file.

- interval:

  numeric values which are part of the specified time intervals.
  Defaults to all intervals being exported

- ...:

  Optional arguments to
  [write.csv](https://rdrr.io/r/utils/write.table.html). \#'

## See also

[write.csv](https://rdrr.io/r/utils/write.table.html)
