# annoRNA
Suite of tools for annotations in RNA-seq data.

## merge
Recently, I mapped RNA-seq reads against
[`Escherichia coli str. K12 substr. DH10B`](https://www.ncbi.nlm.nih.gov/nuccore/170079663?report=genbank&to=4686137) -
NCBI Reference Sequence: NC_010473.1. However, the corresponding annotations are not complete. It turnes out that the NCBI
only lists about 14 ncRNAs, but there are more of them. Strangely enough, there exist
[other genomes of the same organism](https://www.ncbi.nlm.nih.gov/nuccore/CP000948) - GenBank: CP000948.1
with annotations that are either identical or annotated differently. Databases like
[ASAP](https://www.genome.wisc.edu/tools/asap.htm) add a further complication when one considers the ncRNA `rygC` that is
annotated on multiple different genomic locations.

## Input

## Output
Output will be a
