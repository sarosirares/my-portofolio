function [Af] = convolution2D(A, h)
    [aRows, aCols] = size(A);
    [hRows, hCols] = size(h);
    
    nRows = floor(hRows / 2);
    nCols = floor(hCols / 2);
    
    Af = zeros(aRows, aCols);
    
    for x = 1:aRows
        for y = 1:aCols
            sum = 0;
            for i = -nRows:nRows
                for j = -nCols:nCols
                    % Wrap around for row and column indices
                    xi = mod(x - i - 1, aRows) + 1;
                    yj = mod(y - j - 1, aCols) + 1;
                    
                    % Kernel index
                    hi = i + nRows + 1;
                    hj = j + nCols + 1;
                    
                    sum = sum + h(hi, hj) * A(xi, yj);
                end
            end
            Af(x, y) = sum;
        end
    end
end