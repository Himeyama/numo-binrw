# frozen_string_literal: true

require_relative "lib/numo/binrw/version"

Gem::Specification.new do |spec|
  spec.name          = "numo-binrw"
  spec.version       = Numo::Binrw::VERSION
  spec.authors       = ["Murata Mitsuharu"]
  spec.email         = ["hikari.photon+mygit@gmail.com"]

  spec.summary       = "Read binary files and handle them with `NArray`."
  spec.description   = "Read binary files and handle them with `NArray`."
  spec.homepage      = "https://github.com/himeyama/numo-binrw"
  spec.license       = "MIT"
  spec.required_ruby_version = ">= 2.4.0"

  spec.files = Dir.chdir(File.expand_path(__dir__)) do
    `git ls-files -z`.split("\x0").reject { |f| f.match(%r{\A(?:test|spec|features)/}) }
  end
  spec.bindir        = "exe"
  spec.executables   = spec.files.grep(%r{\Aexe/}) { |f| File.basename(f) }
  spec.require_paths = ["lib", "ext"]
  spec.extensions    = ["ext/numo/binrw/extconf.rb"]

  spec.add_development_dependency "rake", ">= 12.3.3"
  spec.add_development_dependency "rake-compiler", "~> 1.1.1"
  spec.add_development_dependency "numo-narray", "~> 0.9.2.0"
end
