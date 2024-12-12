A solution to the Nov 2024 IBM Ponder This puzzle.

For a tetrahedoron with sides u,v,w,U,V,W (with pairs u,U, v,V, w,W opposite each other), the volume of the tetrahedron is given by the formulae

144*(Volume)^2 = T = 4(u^2 v^2 w^2) - u^2(v^2 + w^2 - U^2)^2 - v^2(w^2 + u^2 - V^2)^2
        - w^2(u^2 + v^2 - W^2)^2 + (v^2 + w^2 - U^2)(w^2 + u^2 - V^2)(u^2 + v^2 - W^2)
		
So we are looking for integers u,v,w,U,V,W satisfying this equation for T=128 and T=655

Considering this formula as a quadratic in x = w^2, x satisfies

x = w^2 =  (uU - uV + uW - Uv + UW + vV + vW + VW - WW  ± sqrt(d))/(2W)

where d = 4W(-T - u^2U + u(-U^2 + U(v + V + W) + v(V - W)) - V(U(W - v) + v(v + V - W)))
          + (u(U - V + W) + U(W - v) + vV + vW + VW - W^2)^2		
		  
The program searches integer values of 	u,v,U,V,W for T=128 and T=655 to find integer values of w.	  
