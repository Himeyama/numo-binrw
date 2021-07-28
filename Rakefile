# frozen_string_literal: true

require "bundler/gem_tasks"
task default: %i[]


require "rake/extensiontask"
Rake::ExtensionTask.new "numo/binrw" do |ext|
    ext.lib_dir = "ext"
end

require "rake/testtask"
Rake::TestTask.new :test do |t|
    t.libs << "test"
    t.libs << "lib"
    t.verbose = true
    t.test_files = FileList["test/*.rb"]
end