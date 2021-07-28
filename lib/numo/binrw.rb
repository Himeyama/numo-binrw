# frozen_string_literal: true

require_relative "binrw/version"

require "numo/narray"
require "numo/binrw.so"

module Numo
    module Binrw
        class Error < StandardError; end
    end

    class DFloat
        def bin_write(filename)
            if filename.is_a? Array
                if ndim != 2
                    # 複数行う場合は行列
                    raise "If multiple files are specified, it must be a matrix"
                end
                if shape[0] != filename.size
                    # ファイル数と行数は同じ
                    raise "If multiple files are specified, the number of files and the number of lines must be the same"
                end
            elsif filename.is_a? String
            else
                raise
            end

            if self.is_a? DFloat
                dfloat_bin_write(filename)
            end
            self
        end
    end
end
