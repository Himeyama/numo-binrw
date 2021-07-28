# frozen_string_literal: true

require_relative "binrw/version"

module Numo
    module Binrw
        class Error < StandardError; end
    end
end

require "numo/binrw.so"