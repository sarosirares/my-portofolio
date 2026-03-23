function Af = myConv2D(A, h)
    % Get the sizes
    [aRows, aCols] = size(A);
    [hRows, hCols] = size(h);
    
    % Determine half sizes of the kernel
    nRows = floor(hRows / 2);
    nCols = floor(hCols / 2);
    
    % Pad the input image with zeros
    paddedA = padarray(A, [nRows, nCols], 0, 'both');
    
    % Initialize the output
    Af = zeros(aRows, aCols);
    
    % Perform convolution
    for x = 1:aRows
        for y = 1:aCols
            sum = 0;
            for i = -nRows:nRows
                for j = -nCols:nCols
                    % Shifted indices in the padded image
                    Ai = x + i + nRows;
                    Aj = y + j + nCols;
                    % Kernel index (flipped for convolution)
                    hi = i + nRows + 1;
                    hj = j + nCols + 1;
                    sum = sum + h(hi, hj) * paddedA(Ai, Aj);
                end
            end
            Af(x, y) = sum;
        end
    end
end