# Function to compute resulting isotopic values out of historic ones

Given renewal rates for different isotopic probes over time and normal
distributions of isotopic values over time, resulting normal
distributions of the isotopic probes are calculated.

## Usage

``` r
computeResult(data, timeVars, boneVars = NULL, meanVar, sdVar, cor = 0.5)
```

## Arguments

- data:

  A dataframe specifying the renewal rates of different probes for each
  time interval. The renewal rates should be between 0 and 100
  (percentages). The dataframe should include a column specifying a
  time-index (e.g. 1, 2, 3, ...) as well as columns for the different
  bones. Furthermore, the dataframe should contain the mean and sd
  values for each time interval.

- timeVars:

  A character string specifying the name of the column indicating the
  time.

- boneVars:

  A vector of character strings indicating the relevant variables
  containing the renewal rates of bones and teeth.

- meanVar:

  A character string specifying the name of the column indicating the
  mean values of the isotopic probes over time.

- sdVar:

  A character string specifying the name of the column indicating the
  standard deviation of the isotopic probes over time.

- cor:

  The temporal correlation between neighbouring time points. Defaults to
  0.5

## Value

A data.frame containing the resulting mean and standard deviation for
each bone/tooth as well as the covariances.

## See also

[estimateIntervals](https://pandora-isomemo.github.io/OsteoBioR/reference/estimateIntervals.md)

## Examples

``` r
testDat <- data.frame(
  t = 1:3,
  bone = c(100, 50, 0),
  mean = c(1, 3, 50),
  sd = c(1, 3, 50)
)
  computeResult(
  data = testDat,
  timeVars = "t",
  boneVars = "bone",
  meanVar = "mean",
  sdVar = "sd"
)
#>          mean      sd
#> bone 1.999994 1.80277
```
