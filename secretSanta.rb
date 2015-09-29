big_array  =  ARGF
santas = {}
list = {}

big_array.each_line do |line|
  first_name, last_name, email  = line.split
  id = "#{last_name[0..3]}#{first_name[0...3]}".to_sym
  santas[id] = [first_name, last_name, email]
end

def picker(santa,gifted)
  r = Random.new
  rand = r.rand(gifted.size)
  #puts "#{gifted[rand].to_s}   ###    selected by ## #{santa}"
  #puts "#{santa[1]}  ---->  #{gifted[rand][1][1]}"
  return gifted[rand][0] unless santa[1] == gifted[rand][1][1]
end

gifted = santas.to_a
until gifted.size == 0 do
  list = {}
  gifted = santas.to_a

  santas.each do |id,name|
    list[id] = picker(name,gifted)
	gifted.delete_if{|item| item[0] == list[id]}
	#puts "#{id.to_s} = list[id] = #{list[id]}"
	#puts "#{gifted.size}"
  end 
end

list.each do |k,v|
  puts "#{santas[k].to_s} \t>emails>\t #{santas[v].to_s}"
end
