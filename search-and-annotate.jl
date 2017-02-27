using ArgParse
using Bio.Align
using Bio.Seq

using Bio.Intervals.GFF3Reader

# parse options on command line when started
function parse_command_line()
    settings = ArgParseSettings(
        prog="search-and-annotate",
        version="0.0.1",
        add_version = true)
    @add_arg_table settings begin
        "--features", "-f"
        help = "Features (of all sorts) of the genome that are generally derived from NCBI. Must be provided in the Generic Feature Format version 3 (GFF3)"
        arg_type = String
        "--efeatures", "-e"
        help = "Features (mostly RNAs) that are to be classified into the 'features' list"
        arg_type = String
    end
    return parse_args(settings)
end

function read_features(args)
  reader = open(GFF3Reader,"./input/NC_010473.1_Escherichia_coli_str._K12_substr._DH10B,_.gff3")
  for record in reader
    println(record)
  end
  close(reader)
end


function annotation(args, ref)
    filehandle = open(args["input"])
    for line in eachline(filehandle)
        line = replace(line,"\"","") # replace quotes
        line = replace(line,"\n","")
        row = split(line, "\t")

        alignment = sequence_alignment(row[2],ref)

        println(distance(alignment))


    end
end

function main()
    parsed_args = parse_command_line()
    #go(parsed_args)
    # parse and load the reference sequence


    read_features(parsed_args)

end

main()
