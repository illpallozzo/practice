#fail toward success sorting algorythm

arguments =  ARGF
primary_list = {}
return_list = {}

arguments.each_line do |line|
  first_name, last_name, email  = line.split
  id = "#{last_name[0..3]}#{first_name[0...3]}".to_sym
  primary_list[id] = [first_name, last_name, email]
end

def picker(selected,remaining)
  r = Random.new
  rand = r.rand(remaining.size)
  return remaining[rand][0] unless selected[1] == remaining[rand][1][1]
end

remaining = primary_list.to_a

until remaining.size == 0 do
  temp = {}
  remaining = primary_list.to_a

  primary_list.each do |id,selected|
    return_list[id] = picker(selected,remaining)
    puts "#{id} -->  #{remaining.size}"
    remaining.delete_if{|chosen| chosen[0] == return_list[id]}
  end 
end

return_list.each do |k,v|
  puts "#{primary_list[k][2].to_s} \t>emails>\t #{primary_list[v][2].to_s}"
end
