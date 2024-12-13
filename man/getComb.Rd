% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/02-breakPoints.R
\name{getComb}
\alias{getComb}
\title{Get the comb matrix}
\usage{
getComb(segments, priors)
}
\arguments{
\item{segments}{A matrix containing the segmented formulas}

\item{priors}{A matrix containing the priors}
}
\value{
A matrix containing the segmented formulas and priors
}
\description{
Get the combined matrix of segments and priors.
Process the segments and priors matrices, identify relevant rows and columns, concatenate them,
and generate possible cell combinations while ensuring data consistency.
}
