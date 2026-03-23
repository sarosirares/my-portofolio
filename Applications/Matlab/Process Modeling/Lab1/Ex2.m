% function val = factorial(n)
%     val = 1;
%     for i = 1:n
%         val = val*i;
%     end
% end

function val = factorial(n)
    if n == 1 || n == 0
        val = 1;
    else
        val = n*factorial(n-1);
    end
end

factorial(4)