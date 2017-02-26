using ArgParse
using Bio.Align

# parse options on command line when started
function parse_command_line()
    settings = ArgParseSettings(prog="search-and-annotate",
        version="0.0.1",
        add_version = true)
    @add_arg_table settings begin
        "--input", "-i"
        help = "samfile"
        arg_type = String
        "--genome", "-g"
        help = "genome to be aligned against in fasta format"
        arg_type = String
    end
    return parse_args(settings)
end

# parse the genome file for alignment
function parse_sequence(args)
  sequence = ""
  filehandle = open(args["genome"])
  for line in eachline(filehandle)
    if(line[1] == '>') # skip identifier line
      continue
    end
    sequence = sequence * line # concat lines of (only) sequence
  end
  return sequence
end

# align s1 (query) vs. s2 (reference)
function sequence_alignment(s1,s2)
  problem = GlobalAlignment()
  costmodel = CostModel(match=0, mismatch=1, insertion=1, deletion=1)
  return pairalign(EditDistance(), s1, s2, costmodel)
end

function search(args)
    filehandle = open(args["input"])
    for line in eachline(filehandle)
        line = replace(line,"\"","") # replace quotes
        line = replace(line,"\n","")
        row = split(line, "\t")
        println(row[2])

    end
end

function main()
    parsed_args = parse_command_line()
    #go(parsed_args)
    # parse and load the reference sequence
    reference = parse_sequence(parsed_args)
end

main()
