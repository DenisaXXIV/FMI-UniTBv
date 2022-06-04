using AutoMapper;
using Hotel_WPF.BL.Interfaces;
using Hotel_WPF.DAL.Entities;
using Hotel_WPF.DAL.Interfaces;
using Hotel_WPF.TL.DTO;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.BL.Classes
{
    public class OfferLogic : IEntityLogic<OfferDTO>
    {
        private readonly IHotelRepository<Offer> _repository;
        private readonly IMapper _mapper;

        public OfferLogic(IHotelRepository<Offer> repository, IMapper mapper)
        {
            _repository = repository;
            _mapper = mapper;
        }

        public async Task Add(OfferDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<Offer>(entityDTO);
                await _repository.Add(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        public async Task<List<OfferDTO>> GetAll()
        {
            var results = _mapper.Map<List<OfferDTO>>(await _repository.GetAll());
            return results;
        }

        public async Task<OfferDTO> GetByName(string name)
        {
            if (name == null)
            {
                throw new ArgumentNullException(nameof(name));
            }
            OfferDTO result;
            try
            {
                var results = _mapper.Map<List<OfferDTO>>(await _repository.GetAll());
                result = results.FirstOrDefault(a => a.Name == name);
                if (result == null)
                {
                    throw new DbUpdateException();
                }
                return result;
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        public async Task Remove(OfferDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                await _repository.Delete(entityDTO.IdOffer);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }



        public async Task Update(OfferDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<Offer>(entityDTO);
                await _repository.Update(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }
    }
}
