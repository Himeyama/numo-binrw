# frozen_string_literal: true

require_relative "binrw/version"

require "numo/narray"
require "numo/binrw.so"

module Numo
    module Binrw
        class Error < StandardError; end

        def self.bin_write(obj, filename)
            if filename.is_a? Array
                if obj.ndim != 2
                    # 複数行う場合は行列
                    raise "If multiple files are specified, it must be a matrix"
                end
                if obj.shape[0] != filename.size
                    # ファイル数と行数は同じ
                    raise "If multiple files are specified, the number of files and the number of lines must be the same"
                end
            elsif filename.is_a? String
            else
                raise
            end

            Numo::Binrw._bin_write(obj, filename)
            obj
        end
    end

    class DFloat
        def bin_write(filename)
            Numo::Binrw.bin_write(self, filename)
        end
    end

    class SFloat
        def bin_write(filename)
            Numo::Binrw.bin_write(self, filename)
        end
    end

    class Int32
        def bin_write(filename)
            Numo::Binrw.bin_write(self, filename)
        end
    end

    class Int64
        def bin_write(filename)
            Numo::Binrw.bin_write(self, filename)
        end
    end
end
