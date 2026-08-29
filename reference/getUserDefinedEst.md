# Calculate estimates for user defined intervals

Calculate estimates for user defined intervals

## Usage

``` r
getUserDefinedEst(object, minim = 0, maxim = 1, type = "1")
```

## Arguments

- object:

  model of class
  [`TemporalIso`](https://pandora-isomemo.github.io/OsteoBioR/reference/TemporalIso-class.md)

- minim:

  numeric lower interval point

- maxim:

  numeric upper interval point

- type:

  character "1" for absolute values, "2" for total turnover

## Value

a data.frame containing mean and sd within the interval
