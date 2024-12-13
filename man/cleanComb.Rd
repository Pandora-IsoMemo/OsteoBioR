% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/02-breakPoints.R
\name{cleanComb}
\alias{cleanComb}
\title{Clean the comb matrix}
\usage{
cleanComb(comb)
}
\arguments{
\item{comb}{A matrix containing the segmented formulas and priors}
}
\value{
A cleaned matrix
}
\description{
Check each row for '*+*' and if found replace that cell and all following cells in the row with "".
Remove Blank Rows. Remove duplicate rows.
}
