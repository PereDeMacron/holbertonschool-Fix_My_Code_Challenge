###
#
#  Sort integer arguments (ascending)
#
###

result = ARGV.select { |arg| arg =~ /^-?\d+$/ }.map(&:to_i).sort

puts result
