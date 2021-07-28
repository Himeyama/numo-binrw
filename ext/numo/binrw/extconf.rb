require "mkmf"

narray_dir = Gem.find_files("numo").map{|e| e.include?("narray") ? e : false}.select{|e| e}.to_a[0]
dir_config('narray', narray_dir, narray_dir)
have_library("narray")

create_makefile "numo/binrw"