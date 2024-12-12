A solution to the Nov 2024 IBM Ponder This puzzle.

For a tetrahedoron with sides u,v,w,U,V,W (with pairs u,U, v,V, w,W opposite each other), the volume of the tetrahedron is given by the formulae

144*(Volume)² = T = 4(u²v²w²)-u²(v²+w²-U²)²-v²(w²+u²-V²)² -w²(u²+v²-W²)²+(v²+w²-U²)(w²+u²-V²)(u²+v²-W²)
		
So we are looking for integers u,v,w,U,V,W satisfying this equation for T=128 and T=655

Considering this formula as a quadratic in x = w², x satisfies

x = w² =  (uU-uV+uW-Uv+UW+vV+vW+VW-WW  ± sqrt(d))/(2W)

where d = 4W(-T-u²U + u(-U²+U(v+V+W)+v(V-W))-V(U(W-v)+v(v+V-W))) + (u(U-V+W) + U(W-v) + vV+vW+VW-W²)²		
		  
The program searches integer values of 	u,v,U,V,W for T=128 and T=655 to find integer values of w.	  
