/*=========================================================================

   Copyright 2012 Patrick IMBO
   Contributed to ORFEO Toolbox under license Apache 2

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

=========================================================================*/
#ifndef __otbHorizontalVerticalBaselineFunctor_h
#define __otbHorizontalVerticalBaselineFunctor_h

#include "itkObjectFactory.h"
#include "itkLightObject.h"
#include "otbBaselineFunctorBase.h"
#include <vnl/vnl_vector.h>

namespace otb
{

namespace Functor {

/** \class otbHorizontalVerticalBaselineFunctor
 * HorizontalVerticalBaselineFunctor evaluate the horizontal and vertical baseline from 
 * the baseline vector estimate in an (Radial,Tangential,Normal) referential associated to
 * the master plateform position :
 * $$\vec{B}=(\begin{array}{ccc} B_{R} & B_{T} & B_{N} \end{array})^{T} $ 
 * 
 * Horizontal baseline is: $ B_{N} $
 * Vertical baseline is: $ -B_{R} $
 *
 * \ingroup Functor
 */

class ITK_EXPORT HorizontalVerticalBaselineFunctor : public BaselineFunctorBase
{
public:

  typedef HorizontalVerticalBaselineFunctor             Self;
  typedef BaselineFunctorBase                           Superclass;
  typedef itk::SmartPointer<Self>                       Pointer;
  typedef itk::SmartPointer<const Self>                 ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro( Self );

  /** Run-time type information (and related methods). */
  itkTypeMacro(HorizontalVerticalBaselineFunctor, BaselineFunctorBase);

  typedef Superclass::VectorType  VectorType;

  typedef enum {Horizontal, Vertical, Tangential} BaselineCalculusEnumType;


  virtual OutputType GetHorizontalBaseline() const;
  virtual OutputType GetVerticalBaseline() const;

  OutputType GetBaseline(int);

protected:
  HorizontalVerticalBaselineFunctor() {};
  ~HorizontalVerticalBaselineFunctor() {};

  void PrintSelf(std::ostream& os, itk::Indent indent) const;

private:
  HorizontalVerticalBaselineFunctor(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented
};

		
} // end namespace functor
} // end namespace otb

//#ifndef ITK_MANUAL_INSTANTIATION
//#include "otbHorizontalVerticalBaselineFunctor.cxx"
//#endif

#endif /* __otbParallelPerpendicularBaselineFunctor_h */
